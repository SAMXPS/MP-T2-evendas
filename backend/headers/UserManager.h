#ifndef USER_MANAGER_H_INCLUDED
#define USER_MANAGER_H_INCLUDED
#include "classes/User.h"
#include <string>

class UserManager {
    public:
        /**
         * @brief Carrega um usuario
         * 
         * Carrega os dados de um usuário.
         * @return Ponteiro para usuário. Se o usuário não for encontrado, retorna ponteiro para nulo.
         * 
         */
        static User* loadUser(const std::string&email);

        /**
         * @brief verifica usuário e senha.
         * 
         * @return Se a senha for válida, retorna ponteiro para Usuário.
         * Se a senha for inválida ou o usuário não for encontrado, retorna ponteiro para nulo.
         */
        static User* verifyLogin(const std::string&email, const std::string&senha);

        /**
         * @brief Registra um usuário
         * 
         * Registra um usuario com algumas informações.
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool registerUser(const std::string&email, const std::string&nome, const std::string&senha);

        /**
         * @brief Remove usuario
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool removeUser(const std::string&email);
};

#endif//USER_MANAGER_H_INCLUDED