#include "AgendaUI.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include "Date.h"
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;

bool logout = false;
bool deleteuser = false;

AgendaUI::AgendaUI() {}

void AgendaUI::OperationLoop(void) {
    while (1) {
        startAgenda();
        string s;
        cin >> s;
        if (s == "l" || s == "L") userLogIn();  // 登录后将一系列操作写在死循环中
        else if (s == "r" || s == "R") userRegister();
        else if (s == "q" || s == "Q") quitAgenda();
        else cout << endl << "[error] Invalid Input!" << endl;
    }
}

void AgendaUI::startAgenda(void) {
    for (int i = 0; i < 25; ++i) cout << '-';
    cout << " Agenda ";
    for (int i = 0; i < 28; ++i) cout << '-';

    cout << endl << endl << "Agenda:" << endl;
    cout << "l   -login Agenda by user name and password" << endl;
    cout << "r   -register an Agenda account" << endl;
    cout << "q   -quit Agenda" << endl << endl;

    for (int i =0; i < 60; ++i) cout << '-';
    cout << endl << endl << "Agenda : ~$ ";
}

string AgendaUI::getOperation() {
    cout << endl << endl;
    for (int i = 0; i < 25; ++i) cout << '-';
    cout << " Agenda ";
    for (int i = 0; i < 28; ++i) cout << '-';

    cout << endl << "Agenda : " << endl;
    cout << "o    -log out Agenda" << endl;
    cout << "dc   -delete Agenda account" << endl;
    cout << "lu   -list all Agenda account" << endl;
    cout << "cm   -create a meeting" << endl;
    cout << "la   -list all meetings" << endl;
    cout << "las  -list all sponsor meetings" << endl;
    cout << "lap  -list all participate meetings" << endl;
    cout << "qm   -query meeting by title" << endl;
    cout << "qt   -query meeting by time interval" << endl;
    cout << "dm   -delete meeting by title" << endl;
    cout << "da   -delete all meetings" << endl;
    for (int i = 0; i < 60; ++i) cout << '-';
    cout << endl << endl << "Agenda@" << userName_ << " : # ";

    string s;
    cin >> s;
    return s;
}

bool AgendaUI::executeOperation(string op) {
    if (op == "o") {
        userLogOut();
        logout = true;
        return true;
    }
    if (op == "dc") {
        agendaService_.deleteUser(userName_, userPassword_);
        deleteUser();
        deleteuser = true;
        return true;
    }
    if (op == "lu") {
        listAllUsers();
        cout << endl << "Press ENTER to continue.. ";
        getchar();
        getchar();
        return true;
    }
    if (op == "cm") {
        createMeeting();
        string title, par, sd, ed;
        cin >> title >> par >> sd >> ed;
        if (agendaService_.createMeeting(userName_, title, par, sd, ed)) {
            cout << "[create meeting] succeed!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return true;
        } else {
            cout << "[error] create meeting fail!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return false;
        }
    }
    if (op == "la") {
        listAllMeetings();
        cout << endl << "Press ENTER to continue.. ";
        getchar();
        getchar();
        return true;
    }
    if (op == "las") {
        listAllSponsorMeetings();
        cout << endl << "Press ENTER to continue.. ";
        getchar();
        getchar();
        return true;
    }
    if (op == "lap") {
        listAllParticipateMeetings();
        cout << endl << "Press ENTER to continue.. ";
        getchar();
        getchar();
        return true;
    }
    if (op == "qm") {
        queryMeetingByTitle();
        string s;
        cin >> s;
        if ((agendaService_.meetingQuery(userName_, s)).size() == 0) {
            cout << "[error] Invalid Title!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return false;
        } else {
            printMeetings(agendaService_.meetingQuery(userName_, s));
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return true;
        }
    }
    if (op == "qt") {
        queryMeetingByTimeInterval();
        string sd, ed;
        cin >> sd >> ed;
        if ((agendaService_.meetingQuery(userName_, sd, ed)).size() == 0) {
            cout << "[error] Invalid Time!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return false;
        } else {
            printMeetings(agendaService_.meetingQuery(userName_, sd, ed));
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return true;
        }
    }
    if (op == "dm") {
        deleteMeetingByTitle();
        string title;
        cin >> title;
        if (agendaService_.deleteMeeting(userName_, title)) {
            cout << "[delete meeting by title] succeed!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return true;
        } else {
            cout << "[error] delete meeting fail!" << endl;
            cout << endl << "Press ENTER to continue.. ";
            getchar();
            getchar();
            return false;
        }
    }
    if (op == "da") {
        deleteAllMeetings();
        cout << endl << "Press ENTER to continue.. ";
        getchar();
        getchar();
        return true;
    }
}

void AgendaUI::userLogIn(void) {
    cout << endl << "[log in] [user name] [password]" << endl;
    cout << "[log in] ";
    cin >> userName_ >> userPassword_;
    if (agendaService_.userLogIn(userName_, userPassword_)) {
        cout << "[log in] succeed!" << endl;
        logout = false, deleteuser = false;
        while (1) {
            if (logout == true) break;
            if (deleteuser == true) break;
            executeOperation(getOperation());
        }
    }
    else cout << "[error] log in fail!" << endl << endl;
}

void AgendaUI::userRegister(void) {
    cout << "[register] [user name] [password] [email] [phone]" << endl;
    cout << "[register] ";
    string un, pa, e, ph;
    cin >> un >> pa >> e >> ph;
    if (agendaService_.userRegister(un, pa, e, ph))
        cout << "[register] succeed!" << endl << endl;
    else cout << "[error] register fail!" << endl << endl;
}

void AgendaUI::quitAgenda() {
    agendaService_.quitAgenda();
    exit(0);
}






void AgendaUI::userLogOut() {
    cout << "\n";
}

void AgendaUI::deleteUser(void) {
    cout << endl << "[delete agenda account] succeed!" << endl;
}

void AgendaUI::listAllUsers(void) {
    cout << endl << "[list all users] " << endl;
    list<User> tmp = agendaService_.listAllUsers();
    list<User>::iterator it = tmp.begin();
    cout << setw(10) << left << "name";
    cout << setw(16) << left << "email";
    cout << setw(16) << left << "phone" << endl;
    if (tmp.size() == 1) {
        cout << setw(10) << left << it->getName();
        cout << setw(16) << left << it->getEmail();
        cout << setw(16) << left << it->getPhone() << endl;
    } else {
        for (; it != tmp.end(); ++it) {
            cout << setw(10) << left << it->getName();
            cout << setw(16) << left << it->getEmail();
            cout << setw(16) << left << it->getPhone() << endl;
        }
    }
}

void AgendaUI::createMeeting(void) {
    cout << endl << "[create meeting] [title] [participator]";
    cout << " [start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]";
    cout << endl << "[create meeting] ";
}

void AgendaUI::listAllMeetings(void) {
    cout << endl << "[list all meetings]" << endl << endl;
    list<Meeting> tmp = agendaService_.listAllMeetings(userName_);
    if (tmp.size() == 0) cout << "None" << endl;
    else printMeetings(tmp);
}

void AgendaUI::listAllSponsorMeetings(void) {
    cout << endl << "[list all sponsor meetings]" << endl << endl;
    list<Meeting> tmp = agendaService_.listAllSponsorMeetings(userName_);
    if (tmp.size() == 0) cout << "None" << endl;
    else printMeetings(tmp);
}


void AgendaUI::listAllParticipateMeetings() {
    cout << endl << "[list all participate meetings]" << endl << endl;
    list<Meeting> tmp = agendaService_.listAllParticipateMeetings(userName_);
    if (tmp.size() == 0) cout << "None" << endl;
    else printMeetings(tmp);
}

void AgendaUI::queryMeetingByTitle() {
    cout << endl << "[query meeting] [title]:" << endl;
    cout << "[query meeting] ";
}
    

void AgendaUI::queryMeetingByTimeInterval() {
    cout << endl << "[query meetings] [start time(yyyy-mm-dd/hh:mm)]";
    cout << " [end time(yyyy-mm-dd/hh:mm)]" << endl;
    cout << "[query meetings] ";
}

void AgendaUI::deleteMeetingByTitle() {
    cout << endl << "[delete meetings] [title]" << endl;
    cout << "[delete meetings] ";
}

void AgendaUI::deleteAllMeetings() {
    if (agendaService_.deleteAllMeetings(userName_))
        cout << endl << "[delete all meetings] succeed!" << endl;
    else cout << endl << "[error] no meetings!" << endl;
}

void AgendaUI::printMeetings(list<Meeting> m) {
    cout << setw(9) << left << "title" << setw(10) << left << "sponsor";
    cout << setw(15) << left << "participator" << setw(18) << left;
    cout << "start time" << setw(18) << left << "end time" << endl;
    list<Meeting>::iterator it = m.begin();
    for (; it != m.end(); ++it) {
        cout << setw(9) << left << it->getTitle() << setw(10) << left;
        cout << it->getSponsor() << setw(15) << left << it->getParticipator();
        cout << setw(18) << left << Date::dateToString((*it).getStartDate());
        cout << setw(18) << left << Date::dateToString((*it).getEndDate());
        cout << endl;
    }
}
