#include<iostream>
#include<string>
#include<sstream>
#include "Date.h"
using std::string;

Date::Date() {
    year_ = 1000, month_ = 1, day_ = 1;
    hour_ = 0, minute_ = 0;
}

Date::Date(int y, int m, int d, int h, int mi) {
    year_ = y, month_ = m, day_ = d;
    hour_ = h, minute_ = mi;
}

int Date::getYear(void) const {
    return year_;
}

void Date::setYear(int year) {
    year_ = year;
}

int Date::getMonth(void) const {
    return month_;
}

void Date::setMonth(int month) {
    month_ = month;
}

int Date::getDay(void) const {
    return day_;
}

void Date::setDay(int day) {
    day_ = day;
}

int Date::getHour(void) const {
    return hour_;
}

void Date::setHour(int hour) {
    hour_ = hour;
}

int Date::getMinute(void) const {
    return minute_;
}

void Date::setMinute(int minute) {
    minute_ = minute;
}

bool Date::isValid(Date date) {   // 判断年月后分为三大类：31天的月份、30天的月份、2月，若月份合法再依次判断日、时、分
    if (date.year_ <= 999 || date.year_ >= 10000) {
        return false;
    } else { 
        if (date.month_ <= 0 || date.month_ >= 13) {
            return false;
        } else {
            if (date.month_ == 1 || date.month_ == 3 || date.month_ == 5 ||
            date.month_ == 7 || date.month_ == 8 || date.month_ == 10 ||
            date.month_ == 12) {
                if (date.day_ > 31 || date.day_ < 1) {
                    return false;
                } else {
                    if (date.hour_ >= 0 && date.hour_ < 24 && date.minute_ >= 0
                    && date.minute_ < 60) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else if (date.month_ == 6 ||date.month_ == 4 ||date.month_ == 9 || date.month_ == 11) {
                if (date.day_ > 30 || date.day_ < 1) {
                    return false;
                } else {
                    if (date.hour_ >= 0 && date.hour_ < 24 && date.minute_ >= 0 && date.minute_ < 60) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else if (date.month_ == 2) {    // 分闰年、非闰年
                if ((date.year_%4 == 0 && date.year_%100!= 0) || (date.year_%400) == 0) {
                    if (date.day_ > 29 || date.day_ < 1) {
                        return false;
                    } else {
                        if (date.hour_ >= 0 && date.hour_ < 24 &&
                        date.minute_ >= 0 && date.minute_ < 60) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                } else {
                    if (date.day_ > 28 || date.day_ < 1) {
                        return false;
                    } else {
                        if (date.hour_ >= 0 && date.hour_ < 24 &&
                        date.minute_ >= 0 && date.minute_ < 60) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

Date Date::stringToDate(std::string ds) {   // string正确格式：xxxx-xx-xx/xx:xx
    if (ds.size() > 16 || ds.size() < 12) return Date(500, 1, 1, 12, 12);

    int flag = 0, flag1 = 0, flag2 = 0;
    for (int i = 0; i < ds.size(); ++i) {
        if (ds[i] == '-') flag = 1;
        if (ds[i] == '/') flag1 = 1;
        if (ds[i] == ':') flag2 = 1;
    }
    if (flag != 1 || flag1 != 1 || flag2 != 1) return Date(500, 1, 1, 12, 12);

    std::stringstream stream;
    string d, m, y, h, minute;
    unsigned i = 0;
    int di, mi, yi, hi, minutei;

    for (i = 0; ds[i] != '-'; ++i) y += ds[i];
    if (ds[i] != '-') return Date(500, 1, 1, 12, 12);
    for (i++; ds[i] != '-'; ++i) m += ds[i];
    if (ds[i] != '-') return Date(500, 1, 1, 12, 12);
    for (i++; ds[i] != '/'; ++i) d += ds[i];
    if (ds[i] != '/') return Date(500, 1, 1, 12, 12);
    for (i++; ds[i] != ':'; ++i) h += ds[i];
    if (ds[i] != ':') return Date(500, 1, 1, 12, 12);
    for (i++; i < ds.size(); ++i) minute += ds[i];

    stream << y, stream >> yi, stream.clear();
    stream << m, stream >> mi, stream.clear();
    stream << d, stream >> di, stream.clear();
    stream << h, stream >> hi, stream.clear();
    stream << minute, stream >> minutei, stream.clear();
    return Date(yi, mi, di, hi, minutei);
}

string Date::dateToString(Date date) {
    int y = date.getYear(), m = date.getMonth(), d = date.getDay();
    int h = date.getHour(), mi = date.getMinute();

    string ans, tmp;
    std::stringstream stream;
    stream << y, stream >> tmp, stream.clear();
    ans += tmp + '-';

    if (m < 10) {
        stream << m, stream >> tmp, stream.clear();
        ans += '0' + tmp + '-';
    } else {
        stream << m, stream >> tmp, stream.clear();
        ans += tmp + '-';
    }

    if (d < 10) {
        stream << d, stream >> tmp, stream.clear();
        ans += '0' + tmp + '/';
    } else {
        stream << d, stream >> tmp, stream.clear();
        ans += tmp + '/';
    }

    if (h < 10) {
        stream << h, stream >> tmp, stream.clear();
        ans += '0' + tmp + ':';
    } else {
        stream << h, stream >> tmp, stream.clear();
        ans += tmp + ':';
    }

    if (mi < 10) {
        stream << mi, stream >> tmp, stream.clear();
        ans += '0' + tmp;
    } else {
        stream << mi, stream >> tmp, stream.clear();
        ans += tmp;
    }

    return ans;
}

Date &Date::operator=(const Date& date) {
    year_ = date.getYear(), month_ = date.getMonth(), day_ = date.getDay();
    hour_ = date.getHour(), minute_ = date.getMinute();
    return *this;
}

bool Date::operator==(const Date& date) const {
    if ((year_ == date.getYear()) && (month_ == date.getMonth()) &&
    (day_ == date.getDay()) && (hour_ == date.getHour()) &&
    (minute_ == date.getMinute())) return true;
    return false;
}

bool Date::operator>(const Date& date) const {
    if (year_ > date.getYear()) {
        return true;
    } else if (year_ < date.getYear()) {
        return false;
    } else {
        if (month_ > date.getMonth()) {
            return true;
        } else if (month_ < date.getMonth()) {
            return false;
        } else {
            if (day_ > date.getDay()) {
                return true;
            } else if (day_ < date.getDay()) {
                return false;
            } else {
                if (hour_ > date.getHour()) {
                    return true;
                } else if (hour_ < date.getHour()) {
                    return false;
                } else {
                    if (minute_ > date.getMinute()) return true;
                    return false;
                }
            }
        }
    }
}

bool Date::operator<(const Date& date) const {
    if (*this > date) return false;
    if (*this == date) return false;
    return true;
}

bool Date::operator>=(const Date& date) const {
    if (*this > date) return true;
    if (*this == date) return true;
    return false;
}

bool Date::operator<=(const Date& date) const {
    if (*this < date) return true;
    if (*this == date) return true;
    return false;
}
