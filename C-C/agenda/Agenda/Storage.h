#ifndef AGENDA_STORAGE_H
#define AGENDA_STORAGE_H

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&); \
  void operator=(const TypeName&)

#include <list>
#include <string>
#include <functional>

#include "User.h"
#include "Meeting.h"

class Storage {
    private:
        static Storage *instance_;
        DISALLOW_COPY_AND_ASSIGN(Storage);
        Storage();
        std::list<User> userList_;
        std::list<Meeting> meetingList_;

        bool readFromFile(const char *fpath);
        bool writeToFile(const char *fpath);
    public:

        static Storage *getInstance(void);
        ~Storage();

        void createUser(const User&);
        std::list<User> queryUser(std::function<bool(const User&)> filter);

        int updateUser(std::function<bool(const User&)> filter, std::function<void(User&)> switcher);
        // return the number of updated users
        int deleteUser(std::function<bool(const User&)> filter);
        // return the number of deleted users
        void createMeeting(const Meeting&);
        std::list<Meeting> queryMeeting(std::function<bool(const Meeting&)> filter);

        int updateMeeting(std::function<bool(const Meeting&)> filter, std::function<void(Meeting&)> switcher);
        // return the number of updated meetings
        int deleteMeeting(std::function<bool(const Meeting&)> filter);
        // return the number of deleted meetings
        // File IO
        bool sync(void);
};

#endif
