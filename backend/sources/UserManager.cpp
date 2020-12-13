#include "../headers/UserManager.h"
#include "../headers/DatabaseModule.h"
#include <iostream>

User* UserManager::loadUser(const std::string&email) {
    DatabaseResult* result;

    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `users` WHERE `EMAIL` = '" + email + "'");

        if (result != nullptr && result->size() > 0) {
            auto element = result->front();
            return new User(std::stoi(element["ID"]), element["NAME"], element["EMAIL"], element["PASSWORD"]);
        }
    } catch (const DatabaseError&err) { }
    
    return nullptr;
}

User* UserManager::loadUser(int id) {
    DatabaseResult* result;

    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `users` WHERE `ID` = '" + std::to_string(id) + "'");

        if (result != nullptr && result->size() > 0) {
            auto element = result->front();
            return new User(std::stoi(element["ID"]), element["NAME"], element["EMAIL"], element["PASSWORD"]);
        }
    } catch (const DatabaseError&err) { }
    
    return nullptr;
}

UserData* UserManager::loadUserData(int id) {
    DatabaseResult* result;

    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `users_data` WHERE `ID` = '" + std::to_string(id) + "'");

        if (result != nullptr && result->size() > 0) {
            auto element = result->front();
            return new UserData(std::stoi(element["ID"]), element["ADDRESS"], element["DOCUMENT"], element["PHONE_NUMBER"]);
        }
    } catch (const DatabaseError&err) { }
    
    return nullptr;
}

User* UserManager::verifyLogin(const std::string&email, const std::string&password) {
    User* user = loadUser(email);
    if (user != nullptr && user->verifyPassword(password))
        return user;
    return nullptr;
}

bool UserManager::registerUser(const std::string&email, const std::string&name, const std::string&password) {
    if (!loadUser(email)) try {
        DatabaseModule::getInstance()->executeQuery("INSERT INTO `users`(`ID`, `EMAIL`, `NAME`, `PASSWORD`) VALUES (NULL,'" + email + "','" + name + "','" + password + "')");
        return true;
    } catch (const DatabaseError&err) { }

    return false;
}

bool UserManager::saveUserData(const UserData&data) {
    try {
        if (loadUserData(data.getId())) {
            DatabaseModule::getInstance()->executeQuery("UPDATE `users_data` SET ADDRESS='" + data.getAddress() + "', DOCUMENT='" + data.getDocument() + "', PHONE_NUMBER='" + data.getPhoneNumber() + "' WHERE ID='" + std::to_string(data.getId()) + "'");
        } else {
            DatabaseModule::getInstance()->executeQuery("INSERT INTO `users_data`(`ID`, `ADDRESS`, `DOCUMENT`, `PHONE_NUMBER`) VALUES ('" + std::to_string(data.getId()) + "','" + data.getAddress() + "','" + data.getDocument() + "','" + data.getPhoneNumber() + "')");
        }
        return true;
    } catch (const DatabaseError&err) { }
    return false;
}

bool UserManager::removeUser(const std::string&email) {
    User* user = loadUser(email);
    if (user)
        return removeUser(user->getId());
    return false;
}

bool UserManager::removeUser(int id) {
    try {
        std::string _id = std::to_string(id);
        DatabaseModule::getInstance()->executeQuery("DELETE FROM `users` WHERE `ID` = '" + _id + "'");
        DatabaseModule::getInstance()->executeQuery("DELETE FROM `users_data` WHERE `ID` = '" + _id + "'");
        return true;
    } catch (const DatabaseError&err) { }

    return false;
}