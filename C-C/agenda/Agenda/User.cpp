#include "User.h"
#include<string>
#include<iostream>
using std::string;

User::User() {
    name_ = password_ = email_ = phone_ = "";
}

User::User(string un, string up, string ue, string uph) {
    name_ = un, password_ = up, email_ = ue;
    phone_ = uph;
}

string User::getName() const {
    return name_;
}

void User::setName(std::string name) {
    name_ = name;
}

string User::getPassword() const {
    return password_;
}

void User::setPassword(std::string password) {
    password_ = password;
}

string User::getEmail() const {
    return email_;
}

void User::setEmail(std::string email) {
    email_ = email;
}

string User::getPhone() const {
    return phone_;
}

void User::setPhone(std::string phone) {
    phone_ = phone;
}

