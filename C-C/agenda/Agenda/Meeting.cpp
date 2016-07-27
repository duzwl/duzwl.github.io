#include "Meeting.h"
#include "Date.h"
#include<iostream>
using std::string;

Meeting::Meeting() {
    sponsor_ = participator_ = title_ = "";
}

Meeting::Meeting(string s, string p, Date st, Date et, string title) {
    sponsor_ = s, participator_ = p, title_ = title;
    startDate_ = st, endDate_ = et;
}

string Meeting::getSponsor(void) const {
    return sponsor_;
}

void Meeting::setSponsor(std::string sponsor) {
    sponsor_ = sponsor;
}

string Meeting::getParticipator(void) const {
    return participator_;
}

void Meeting::setParticipator(string participator) {
    participator_ = participator;
}

Date Meeting::getStartDate(void) const {
    return startDate_;
}

void Meeting::setStartDate(Date startTime) {
    startDate_ = startTime;
}

Date Meeting::getEndDate(void) const {
    return endDate_;
}

void Meeting::setEndDate(Date endTime) {
    endDate_ = endTime;
}

string Meeting::getTitle(void) const {
    return title_;
}

void Meeting::setTitle(string title) {
    title_ = title;
}
