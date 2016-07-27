#ifndef AGENDAUI_H
#define AGENDAUI_H

#include "AgendaService.h"
#include <iostream>
#include <string>

class AgendaUI {
    public:
        AgendaUI();
        void OperationLoop(void);  // 1级

    private:
        // task functions
        void startAgenda(void);  // 2
        void quitAgenda(void);  // 2

        std::string getOperation();  // 3
        bool executeOperation(std::string op);  // 3

        void userLogIn(void);  // 2
        void userRegister(void);  // 2
        void userLogOut(void);

        void deleteUser(void);  // 4
        void listAllUsers(void);  // 4

        void createMeeting(void);  // 4
        void listAllMeetings(void);  // 4

        void listAllSponsorMeetings(void);  // 4
        void listAllParticipateMeetings(void);  // 4

        void queryMeetingByTitle(void);  // 4
        void queryMeetingByTimeInterval(void);  // 4

        void deleteMeetingByTitle(void);  // 4
        void deleteAllMeetings(void);  // 4

        void printMeetings(std::list<Meeting> meetings);  // 4

        std::string userName_;
        std::string userPassword_;

        AgendaService agendaService_;
};

#endif
