#include<list>
#include<iostream>
#include<string>
#include<functional>
#include<fstream>
#include "User.h"
#include "Meeting.h"
#include "Storage.h"
#include "Date.h"
using std::list;
using std::string;

Storage *Storage::instance_ = NULL;

Storage::Storage() {
    readFromFile("User.csv");
    readFromFile("Meeting.csv");
}

void fromfileU(string &n, string &pass, string &e, string &ph, string tmp) {
    n.clear(), pass.clear(), e.clear(), ph.clear();
    int i = 0;
    for (i = 1; ; ++i) {
        if (tmp[i] == '"' && tmp[i+1] == ',' && tmp[i+2] == '"') break;
        n += tmp[i];
    }
    for (i = i+3; ; ++i) {
        if (tmp[i] == '"' && tmp[i+1] == ',' && tmp[i+2] == '"') break;
        pass += tmp[i];
    }
    for (i = i+3; tmp[i] != '"'; ++i) e += tmp[i];
    for (i = i+3; tmp[i] != '"'; ++i) ph += tmp[i];
}

void fromfileM(string &s, string &p, string &sd, string &ed, string &title, string tmp) {
    s.clear(), p.clear(), sd.clear(), ed.clear(), title.clear();
    unsigned i = 0;
    for (i = 1; ; ++i) {
        if (tmp[i] == '"' && tmp[i+1] == ',' && tmp[i+2] == '"') break;
        s += tmp[i];
    }
    for (i = i+3; ; ++i) {
        if (tmp[i] == '"' && tmp[i+1] == ',' && tmp[i+2] == '"') break;
        p += tmp[i];
    }
    for (i = i+3; tmp[i] != '"'; ++i) sd += tmp[i];
    for (i = i+3; tmp[i] != '"'; ++i) ed += tmp[i];
    for (i = i+3; tmp[i] != '"'; ++i) title += tmp[i];
}

bool Storage::readFromFile(const char *fpath) {
    string tmp(fpath), input;
    if (tmp == "User.csv") {
        std::ifstream userfile(tmp.c_str(), std::ifstream::in);
        if (!userfile) return false;

        string n, pass, e, ph;
        getline(userfile, input);
        getline(userfile, input);
        while (input.size() != 0) {
            fromfileU(n, pass, e, ph, input);
            userList_.push_back(User(n, pass, e, ph));
            getline(userfile, input);
        }
        userfile.close();
    } else if (tmp == "Meeting.csv") {
        std::ifstream meetingfile(tmp.c_str(), std::ifstream::in);
        if (!meetingfile) return false;
        string s0, p, sd, ed, title;
        getline(meetingfile, input);
        getline(meetingfile, input);
        while (input.size() != 0) {
            fromfileM(s0, p, sd, ed, title, input);
            Date ssd = Date::stringToDate(sd), eed = Date::stringToDate(ed);
            meetingList_.push_back(Meeting(s0, p, ssd, eed, title));
            getline(meetingfile, input);
        }
        meetingfile.close();
    }
    return true;
}

bool Storage::writeToFile(const char *fpath) {
    string s(fpath), tmp;
    if (s == "User.csv") {
        std::ofstream userfile(s.c_str());
        if (!userfile) return false;
        userfile << "\"name\",\"password\",\"email\",\"phone\"" << std::endl;
        list<User>::iterator it = userList_.begin();
        for (; it != userList_.end(); ++it) {
            userfile << "\"" << it->getName() << "\",\"";
            userfile << it->getPassword() << "\",\"";
            userfile << it->getEmail() << "\",\"";
            userfile << it->getPhone() << "\"" << std::endl;
        }
        userfile.close();
    } else if (s == "Meeting.csv") {
        std::ofstream meetingfile(s.c_str());
        if (!meetingfile) return false;
        meetingfile << "\"sponsor\",\"participator\",\"";
        meetingfile << "sdate\",\"edate\",\"title\"" << std::endl;
        list<Meeting>::iterator itt = meetingList_.begin();
        for (; itt != meetingList_.end(); ++itt) {
            meetingfile << "\"" << itt->getSponsor() << "\",\"";
            meetingfile << itt->getParticipator() << "\",\"";
            meetingfile << Date::dateToString(itt->getStartDate()) << "\",\"";
            meetingfile << Date::dateToString(itt->getEndDate()) << "\",\"";
            meetingfile << itt->getTitle() << "\"" << std::endl;
        }
        meetingfile.close();
    }
    return true;
}

Storage *Storage::getInstance(void) {
    if (Storage::instance_ == NULL) {
        instance_ = new Storage();
    }
    return instance_;
}

Storage::~Storage() {
    sync();   // 记得同步
    instance_ = NULL;
}

void Storage::createUser(const User&a) {
    instance_->userList_.push_back(a);
}

list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
    list<User> ans;
    list<User> tmp = instance_->userList_;
    list<User>::iterator it = tmp.begin();
    for (; it != tmp.end(); ++it) {
        if (filter(*it))
            ans.push_back(*it);
    }
    return ans;
}

int Storage::updateUser(std::function<bool(const User&)> filter, std::function<void(User&)> switcher) {
    int ans = 0;
    list<User>::iterator it = instance_->userList_.begin();
    for (; it != instance_->userList_.end(); it++) {
        if (filter(*it)) {
            switcher(*it);
            ans++;
        }
    }
    return ans;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
    int ans = 0;
    list<User>::iterator it = instance_->userList_.begin();
    for (; it != instance_->userList_.end(); it++) {
        if (filter(*it)) {
            instance_->userList_.erase(it);
            --it;
            ans++;
        }
    }
    return ans;
}

void Storage::createMeeting(const Meeting&a) {
    instance_->meetingList_.push_back(a);
}

list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting&)> f) {
    list<Meeting> ans;
    list<Meeting>::iterator it = instance_->meetingList_.begin();
    for (; it != instance_->meetingList_.end(); ++it) {
        if (f(*it))
            ans.push_back(*it);
    }
    return ans;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter,
    std::function<void(Meeting&)> switcher) {
    int ans = 0;
    list<Meeting>::iterator it = instance_->meetingList_.begin();
    for (; it != instance_->meetingList_.end(); it++) {
        if (filter(*it)) {
            switcher(*it);
            ans++;
        }
    }
    return ans;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
    int ans = 0;
    list<Meeting>::iterator it = instance_->meetingList_.begin();
    for (; it != instance_->meetingList_.end(); it++) {
        if (filter(*it)) {
            instance_->meetingList_.erase(it);
            --it;
            ans++;
        }
    }
    return ans;
}

bool Storage::sync(void) {
    writeToFile("User.csv");
    return writeToFile("Meeting.csv");
}

