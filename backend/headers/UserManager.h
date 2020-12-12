#ifndef USER_MANAGER_H_INCLUDED
#define USER_MANAGER_H_INCLUDED
#include "classes/User.h"
#include "classes/UserData.h"
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
         * @brief Carrega dados adicionais de um usuario
         * 
         * @return Ponteiro para dados de usuário. Se o usuário não for encontrado, retorna ponteiro para nulo.
         * 
         */
        static UserData* loadUserData(int id);

        /**
         * @brief verifica usuário e senha.
         * 
         * @return Se a senha for válida, retorna ponteiro para Usuário.
         * Se a senha for inválida ou o usuário não for encontrado, retorna ponteiro para nulo.
         */
        static User* verifyLogin(const std::string&email, const std::string&password);

        /**
         * @brief Registra um usuário
         * 
         * Registra um usuario com algumas informações.
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool registerUser(const std::string&email, const std::string&name, const std::string&password);

        /**
         * @brief Salva dados adicionais de usuário.
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool saveUserData(const UserData&data);

        /**
         * @brief Remove usuario
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool removeUser(const std::string&email);

        /**
         * @brief Remove usuario
         * 
         * @return verdadeiro em caso de sucesso.
         */
        static bool removeUser(int id);

};

#endif // USER_MANAGER_H_INCLUDED