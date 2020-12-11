#ifndef _USER_MANAGER
#define _USER_MANAGER
#include <string>
#include <jsoncpp/json/json.h>


/**
 * @brief Classe que contem dados do usuario
 * 
 */
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
     * @param email 
     * @return User* 
     */
    User* loadUser(const std::string&email);

    /**
     * @brief verifica usuário e senha.
     * 
     * Verifica se usuário esta cadastrado.
     * 
     * @param usuario 
     * @param senha 
     * @return std::string 
     */
    std::string verifyLogin(const std::string&email, const std::string&senha);

    /**
     * @brief Registra um usuário
     * 
     * Registra um usuario com algumas informações.
     * 
     * @param name 
     * @param password 
     * @param email 
     * 
     * @return std::string 
     */
    std::string registerUser(const std::string&email, const std::string&nome, const std::string&senha);

    /**
     * @brief Remove usuario
     * 
     * @param email 
     *  
     * @return std::string 
     */
    std::string removeUser(const std::string&email);
};

#endif//_USER_MANAGER