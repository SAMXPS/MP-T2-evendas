#include "../../headers/classes/User.h"

User::User(int id, const std::string&name,const std::string&email,const std::string&password) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}    

int User::getId() {
    return this->id;
}

std::string User::getName() {
    return this->name;
}

std::string User::getEmail() {
    return this->email;
}

std::string User::getPassword() {
    return this->password;
}

bool User::verifyPassword(const std::string&typedPassword) {
    return this->password == typedPassword;
}