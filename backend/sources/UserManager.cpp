#include "../headers/UserManager.h"
#include "../headers/DatabaseModule.h"
#include <iostream>

User* UserManager::loadUser(const std::string&email) {
    DatabaseResult* result;

    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `usuarios` WHERE `EMAIL` = '" + email + "'");

        if (result != nullptr && result->size() > 0) {
            auto element = result->front();
            return new User(std::stoi(element["ID"]), element["NOME"], element["EMAIL"], element["SENHA"]);
        }
    } catch (const DatabaseError&err) { }
    
    return nullptr;
}

User* UserManager::verifyLogin(const std::string&email, const std::string&senha) {
    User* user = loadUser(email);
    if (user != nullptr && user->verifyPassword(senha))
        return user;
    return nullptr;
}

bool UserManager::registerUser(const std::string&email, const std::string&nome, const std::string&senha) {
    if (!loadUser(email)) try {
        DatabaseResult* result = DatabaseModule::getInstance()->executeQuery("INSERT INTO `usuarios`(`ID`, `EMAIL`, `NOME`, `SENHA`) VALUES (NULL,'" + email + "','" + nome + "','" + senha + "')");
        return true;
    } catch (const DatabaseError&err) { }

    return false;
}

bool UserManager::removeUser(const std::string&email) {
    if (loadUser(email)) try {
        DatabaseResult* result = DatabaseModule::getInstance()->executeQuery("DELETE FROM `usuarios` WHERE `EMAIL` = '" + email + "'");
        return result != NULL;
    } catch (const DatabaseError&err) { }

    return false;
}