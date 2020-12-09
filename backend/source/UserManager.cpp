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
        } else {
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

std::string UserManager::registerUser(Json::Value nome, Json::Value senha, Json::Value email, Json::Value cpf, Json::Value phoneNum) {
    try {
        if (UserManager::verifyLogin(email, senha).compare("UNREGISTERED_USER")){
            DatabaseResult* result;
            result = DatabaseModule::getInstance()->executeQuery("INSERT INTO `usuarios`(`ID`, `EMAIL`, `NOME`, `SENHA`) VALUES (0,'" + email.asString() + "','" + nome.asString() + "','" + phoneNum.asString() + "'");
            auto element = result->front();
            if (result->size()>0) {   
                if (element["SENHA"].compare(senha.asString()) == 0 && element["EMAIL"].compare(email.asString()) == 0 && element["NOME"].compare(email.asString()) == 0 && element["EMAIL"].compare(phoneNum.asString()) == 0) {
                    return "SUCCESS";
                }
                else {
                    return "ERROR";
                }
            }
        }
        else {
            return "REGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        std::cout << e.what();
    }
}

std::string UserManager::removeUser(Json::Value email, Json::Value senha) {
    try {
        if (UserManager::verifyLogin(email, senha).compare("VALID_PASSWORD")){
            DatabaseResult* result;
            result = DatabaseModule::getInstance()->executeQuery("DELETE FROM `usuarios` WHERE EMAIL = '" + email.asString() + "'");
            auto element = result->front();
            if (result->size() == 0) {   
                return "SUCCESS";
            } else {
                return "ERROR";
            }
        }
        else {
            return "UNREGISTERED_USER";
        }
    } catch (DatabaseError&e) {
        std::cout << e.what();
    } 
}


User* loadUser(const std::string&email) {

}