#include "../../headers/classes/UserData.h"

UserData::UserData(int id, const std::string&address,const std::string&document,const std::string&phoneNumber) {
    this->id = id;
    this->address = address;
    this->document = document;
    this->phoneNumber = phoneNumber;
}

int UserData::getId() const{
    return this->id;
}

std::string UserData::getAddress() const{
    return this->address;
}

std::string UserData::getDocument() const{
    return this->document;
}

std::string UserData::getPhoneNumber() const{
    return this->phoneNumber;
}

Json::Value UserData::toJson() {
    Json::Value userData;
    userData["id"] = id;
    userData["address"] = address;
    userData["document"] = document;
    userData["phoneNumber"] = phoneNumber;
    return userData;
}