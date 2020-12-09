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
     * @param usuario 
     * @param senha 
     * @param email 
     * @return std::string 
     */
    std::string registerUser(Json::Value usuario, Json::Value senha, Json::Value email);
};

#endif//_USER_MANAGER