#include "../headers/UserManager.h"
#include "../headers/DatabaseModule.h"
#include <iostream>

std::string UserManager::verifyLogin(const std::string&email, const std::string&password) {
    try {
        DatabaseResult* result;
        result = DatabaseModule::getInstance()->executeQuery("SELECT SENHA FROM `usuarios` WHERE EMAIL = '" + email + "'");
        if (result && result->size() > 0) {   
            auto element = result->front();
            if (element["SENHA"] == password) {
                return "VALID_PASSWORD";
            }
            else {
                return "INVALID_PASSWORD";
            }
        } else {
            return "UNREGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        return "DATABASE_ERROR:" + e.what();
    }
}

std::string User::getNome() {
    return this->nome;
}

std::string User::getEmail() {
return this->email;
}

std::string User::getSenha() {
return this->senha;
}
int User::getId() {
return this->id;
}

bool User::verifyPassword(const std::string&senhaDigitada) {
    return this->senha == senhaDigitada;
}

std::string UserManager::registerUser(const std::string&email, const std::string&nome, const std::string&senha) {
    try {
        if (UserManager::loadUser(email) == NULL){
            DatabaseResult* result;
            result = DatabaseModule::getInstance()->executeQuery("INSERT INTO `usuarios`(`ID`, `EMAIL`, `NOME`, `SENHA`) VALUES (NULL,'" + email + "','" + nome + "','" + senha + "')");
            if (UserManager::loadUser(email)->getEmail() == email) {
                return "SUCCESS";
            }
            else {
                return "ERROR";
            }
        }
        else {
            return "REGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        return "DATABASE_ERROR:" + e.what();
    }
}

std::string UserManager::removeUser(const std::string&email) {
    try {
        if (loadUser(email) != NULL){
            DatabaseResult* result;
            result = DatabaseModule::getInstance()->executeQuery("DELETE FROM `usuarios` WHERE EMAIL = '" + email + "'");
            if (loadUser(email) == NULL) {
                return "SUCCESS";
            }
            else {
                return "ERROR";
            }
        }
        else {
            return "UNREGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        return "DATABASE_ERROR:" + e.what();
    } 
}


User* UserManager::loadUser(const std::string&email) {
    DatabaseResult* result;
    result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `usuarios` WHERE EMAIL = '" + email + "'");
    if (result && result->size() > 0) {
        auto element = result->front();
        User *client = new User(std::stoi(element["ID"]), element["NOME"], element["EMAIL"], element["SENHA"]);;
        return client;
    }
    else {
        return NULL;
    }
}