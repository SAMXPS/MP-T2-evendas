// Copyright 2020 Samuel James, Leonam Gomes
#include "../../headers/classes/User.h"

User::User(int id, const std::string&name,const std::string&email,const std::string&password) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}    

int User::getId() const{
    return this->id;
}

std::string User::getName() const{
    return this->name;
}

std::string User::getEmail() const{
    return this->email;
}

std::string User::getPassword() const{
    return this->password;
}

bool User::verifyPassword(const std::string&typedPassword) const{
    return this->password == typedPassword;
}

Json::Value User::toJson() {
    Json::Value user;
    user["id"] = id;
    user["name"] = name;
    user["email"] = email;
    user["password"] = password;
    return user;
}