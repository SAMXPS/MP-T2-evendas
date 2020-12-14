#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Classe que contem dados basicos do usuario
 */
class User {
    private:
        int id;
        std::string name;
        std::string email;
        std::string password;

    public:

        /**
         * @brief Controi um novo objeto User
         * 
         * @param id 
         * @param name 
         * @param email 
         * @param password 
         */
        User(int id, const std::string&name,const std::string&email,const std::string&password);

        /**
         * @brief Pega o id de um usuário
         * 
         * Retorna o Id de um usuário
         * 
         * @return int 
         */
        int getId() const;

        /**
         * @brief Pega o nome de um usuário
         * 
         * Retorna o nome do usuario
         * 
         * @return std::string 
         */
        std::string getName() const;

        /**
         * @brief Pega o email de um usuário
         * 
         * retorna o email de um usuário
         * 
         * @return std::string 
         */
        std::string getEmail() const;

        /**
         * @brief Pega a senha de um usuário
         * 
         * retorna a senha de um usuário
         * 
         * @return std::string 
         */
        std::string getPassword() const;

        /**
         * @brief Verifica a senha
         * 
         * verifica a senha de um usuário
         * 
         * @param typedPassword 
         * @return true 
         * @return false 
         */
        bool verifyPassword(const std::string&typedPassword) const;

        Json::Value toJson();
};

#endif//USER_H_INCLUDED