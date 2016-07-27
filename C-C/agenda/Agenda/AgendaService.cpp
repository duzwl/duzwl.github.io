#include "AgendaService.h"
#include "Storage.h"
#include "Date.h"
#include<list>
#include<iostream>
using std::string;
using std::list;
using std::cout;
using std::endl;

AgendaService::AgendaService() {
    startAgenda();
}

AgendaService::~AgendaService() {
    quitAgenda();
    delete storage_;
    storage_ = NULL;
}

bool AgendaService::userLogIn(string userName, string password) {
    auto filter = [userName, password] (const User& a) -> bool {   // 默认转换为function<bool(const User&)>
        if (a.getName() == userName && a.getPassword() == password) return true;
        return false; };

    int flag = (storage_->queryUser(filter)).size();
    if (flag == 1) return true;
    return false;
}

bool AgendaService::userRegister(string un, string pa, string e, string ph) {
    auto filter = [un] (const User& a) -> bool {
        if (a.getName() == un) return true; return false; };

    int flag = (storage_->queryUser(filter)).size();
    if (flag == 0) {
        storage_->createUser(User(un, pa, e, ph));
        return true;
    }
    return false;
}

bool AgendaService::deleteUser(string userName, string password) {   // 删除用户同时删除会议
    auto ufilter = [userName, password, this] (const User& a) -> bool {
        if (a.getName() == userName && a.getPassword() == password) {
            this->deleteAllMeetings(userName); return true; }
            return false; };

    int flag = storage_->deleteUser(ufilter);
    if (flag == 0) return false;
    return true;
}

list<User> AgendaService::listAllUsers(void) {
    return storage_->queryUser([] (const User& a) { return true; });
}

bool AgendaService::createMeeting(string un, string title, string par, string sd, string ed) {
    auto ufilter = [un, par] (const User& a) -> bool {   // sp, par 都存在
        if (a.getName() == un || a.getName() == par) return true;
        return false; };

    int uflag = (storage_->queryUser(ufilter)).size();
    if (uflag != 2) return false;

    if (!Date::isValid(Date::stringToDate(sd)) || !Date::isValid(Date::stringToDate(ed)))  // 日期合法
        return false;
    if (Date::stringToDate(sd) >= Date::stringToDate(ed)) 
        return false;

    auto mfilter = [un, title] (const Meeting& a) -> bool {
        if (a.getSponsor() == un && a.getTitle() == title) return true;
        return false; };

    int mflag = (storage_->queryMeeting(mfilter)).size();   // sp、title相同则会议间时间不能有重叠
    if (mflag != 0) {
        list<Meeting> tmp = storage_->queryMeeting(mfilter);
        list<Meeting>::iterator itm = tmp.begin();
        for (; itm != tmp.end(); ++itm) {
            if ((itm->getEndDate() > Date::stringToDate(sd) && itm->getEndDate() <= Date::stringToDate(ed))
            || (itm->getStartDate() < Date::stringToDate(ed) && itm->getStartDate() >= Date::stringToDate(sd)))
            return false;
        }
    }
                                                    
    auto m1filter = [un, sd, ed] (const Meeting& a) -> bool {   // sp参与的会议时间与新会议时间无交集
        if ((a.getSponsor() == un && a.getEndDate() > Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getSponsor() == un && a.getStartDate() < Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd))
        || (a.getParticipator() == un && a.getEndDate() > Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getParticipator() == un && a.getStartDate() < Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd)))
            return true; return false; };

    int m1flag = (storage_->queryMeeting(m1filter)).size();
    if (m1flag != 0) return false;

    auto m2filter = [par, sd, ed] (const Meeting& a) -> bool {   // par参与的会议时间与新会议时间无交集
        if ((a.getParticipator() == par && a.getEndDate() > Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getParticipator() == par && a.getStartDate() < Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd))
        || (a.getSponsor() == par && a.getEndDate() > Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getSponsor() == par && a.getStartDate() < Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd)))
            return true; return false; };

    int m2flag = (storage_->queryMeeting(m2filter)).size();
    if (m2flag != 0) return false;

    auto m3filter = [un, par, sd, ed] (const Meeting& a) -> bool {   // sp、par参与的某会议时间不包含新会议时间
        if ((a.getParticipator() == par && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd))
        || (a.getSponsor() == par && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd))
        || (a.getParticipator() == un && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd))
        || (a.getSponsor() == un && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd)))
            return true; return false; };

    int m3flag = (storage_->queryMeeting(m3filter)).size();
    if (m3flag != 0) return false;

    auto m4filter = [un, par, sd, ed] (const Meeting& a) -> bool {   // 新会议时间不包含sp、par参与某会议时间
        if ((a.getParticipator() == par && a.getEndDate() <= Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd))
        || (a.getSponsor() == par && a.getEndDate() <= Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd))
        || (a.getParticipator() == un && a.getEndDate() <= Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd)) 
        || (a.getSponsor() == un && a.getEndDate() <= Date::stringToDate(ed) && a.getStartDate() >= Date::stringToDate(sd))) 
            return true; return false; };

    int m4flag = (storage_->queryMeeting(m4filter)).size();
    if (m4flag != 0) return false;

    storage_->createMeeting(Meeting(un, par, Date::stringToDate(sd), Date::stringToDate(ed), title));
    return true;

}

list<Meeting> AgendaService::meetingQuery(string un, string title) {
    auto filter = [un, title] (const Meeting& a) -> bool {
        if ((a.getSponsor() == un && a.getTitle() == title)
        || (a.getParticipator() == un && a.getTitle() == title)) 
            return true; return false; };

    int flag = (storage_->queryMeeting(filter)).size();
    if (flag == 0) {
        list<Meeting> l;
        return l;
    }
    return storage_->queryMeeting(filter);
}

list<Meeting> AgendaService::meetingQuery(string un, string sd, string ed) {
    list<Meeting> l;
    if (!Date::isValid(Date::stringToDate(ed))
    || !Date::isValid(Date::stringToDate(sd))) return l;

    if (Date::stringToDate(ed) <= Date::stringToDate(sd)) return l;

    auto filter = [un, sd, ed] (const Meeting& a) -> bool {
        if ((a.getSponsor() == un && a.getStartDate() >= Date::stringToDate(sd) && a.getStartDate() <= Date::stringToDate(ed))
        || (a.getSponsor() == un && a.getEndDate() >= Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getSponsor() == un && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd))
        || (a.getParticipator() == un && a.getStartDate() >= Date::stringToDate(sd) && a.getStartDate() <= Date::stringToDate(ed))
        || (a.getParticipator() == un && a.getEndDate() >= Date::stringToDate(sd) && a.getEndDate() <= Date::stringToDate(ed))
        || (a.getParticipator() == un && a.getEndDate() >= Date::stringToDate(ed) && a.getStartDate() <= Date::stringToDate(sd)))
            return true; return false; };

    int flag = (storage_->queryMeeting(filter)).size();
    if (flag == 0) {
        return l;
    }
    return storage_->queryMeeting(filter);
}

list<Meeting> AgendaService::listAllMeetings(string un) {
    auto filter = [un] (const Meeting& a) -> bool {
        if (a.getSponsor() == un || a.getParticipator() == un) return true;
        return false; };

    int flag = (storage_->queryMeeting(filter)).size();
    if (flag == 0) {
        list<Meeting> l;
        return l;
    }
    return storage_->queryMeeting(filter);
}

list<Meeting> AgendaService::listAllSponsorMeetings(string un) {
    auto filter = [un] (const Meeting& a) -> bool {
        if (a.getSponsor() == un) return true; return false; };

    int flag = (storage_->queryMeeting(filter)).size();
    if (flag == 0) {
        list<Meeting> l;
        return l;
    }
    return storage_->queryMeeting(filter);
}

list<Meeting> AgendaService::listAllParticipateMeetings(string un) {
    auto filter = [un] (const Meeting& a) -> bool {
        if (a.getParticipator() == un) return true; return false; };

    int flag = (storage_->queryMeeting(filter)).size();
    if (flag == 0) {
        list<Meeting> l;
        return l;
    }
    return storage_->queryMeeting(filter);
}

bool AgendaService::deleteMeeting(string un, string title) {
    auto filter = [un, title] (const Meeting& a) -> bool {
        if (a.getSponsor() == un && a.getTitle() == title) 
            return true;
        return false; };

    int flag = storage_->deleteMeeting(filter);
    if (flag == 0) return false;
    return true;
}

bool AgendaService::deleteAllMeetings(string un) {
    auto filter = [un] (const Meeting& a) -> bool {
        if (a.getSponsor() == un) return true; return false; };

    int flag = storage_->deleteMeeting(filter);
    if (flag == 0) return false;
    return true;
}

void AgendaService::startAgenda() {
    storage_ = Storage::getInstance();
}

void AgendaService::quitAgenda(void) {
    storage_->sync();
}
