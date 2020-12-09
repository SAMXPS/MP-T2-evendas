#include "../headers/UserManager.h"
#include "../headers/DatabaseModule.h"
#include <iostream>

std::string UserManager::verifyLogin(Json::Value email, Json::Value password) {
    try {
        DatabaseResult* result;
        result = DatabaseModule::getInstance()->executeQuery("SELECT SENHA FROM usuarios WHERE EMAIL = '" + email.asString() + "'");
        if (result->size()>0) {   
            auto element = result->front();
            if (element["SENHA"].compare(password.asString()) == 0) {
                return "VALID_PASSWORD";
            }
            else {
                return "INVALID_PASSWORD";
            }
        }
        else {
            return "UNREGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        std::cout << e.what();
    }
}

/*
void test() {
    try {
        DatabaseResult* result;
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM usuarios");
        if (result) {
            for (auto elemento : *result) {
                std::cout << "Email: " << elemento["EMAIL"] << std::endl;
            }
        }

        std::string email = "bsbcraftplays@gmail.com";
        result = DatabaseModule::getInstance()->executeQuery("SELECT SENHA FROM usuarios WHERE EMAIL = '" + email + "'");
        if (result && result->size() > 0) {
            auto elemento = result->front();
            std::cout << "Senha: " << elemento["SENHA"] << std::endl;
        }

    } catch (DatabaseError&e) {
        std::cout << e.what();
    }
}
*/

std::string User::getNome() {
    return this->nome;
}

bool User::verifyPassword(const std::string&senhaDigitada) {
    return this->senha == senhaDigitada;
}

std::string UserManager::registerUser(Json::Value nome, Json::Value senha, Json::Value email) {
    return "OK";
}

User* loadUser(const std::string&email) {

}