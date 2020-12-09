#ifndef _USER_MANAGER
#define _USER_MANAGER
#include <string>
#include <jsoncpp/json/json.h>

class User {
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;

    public:
        User(int id, const std::string&nome,const std::string&email,const std::string&senha) {
            this->id = id;
            this->nome = nome;
            this->email = email;
            this->senha = senha;
        }

        int getId();
        std::string getNome();
        std::string getEmail();
        std::string getSenha();

        bool verifyPassword(const std::string&senha);
};

namespace UserManager {

    /**
     * @brief Carrega um usuario
     * 
     * Carrega os dados de um usuário.
     * 
     * @param userID 
     * @return User* 
     */
    User* loadUser(const std::string&userID);

    /**
     * @brief verifica usuário e senha.
     * 
     * Verifica se usuário esta cadastrado.
     * 
     * @param usuario 
     * @param senha 
     * @return std::string 
     */
    std::string verifyLogin(Json::Value email, Json::Value password);

    /**
     * @brief Registra um usuário
     * 
     * Registra um usuario com algumas informações.
     * 
     * @param name 
     * @param password 
     * @param email 
     * @param cpf 
     * @param phoneNum 
     * @return std::string 
     */
    std::string registerUser(Json::Value name, Json::Value password, Json::Value email, Json::Value cpf, Json::Value phoneNum);

    /**
     * @brief Remove usuario
     * 
     * @param email 
     * @param senha 
     * @return std::string 
     */
    std::string removeUser(Json::Value email, Json::Value senha);
};

#endif//_USER_MANAGER