#ifndef _JSON_MODULE
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Modulo que processa as requisições e respostas ao cliente
 * 
 */
namespace JsonModule{
    /**
     * @brief verifica usuário e senha.
     * 
     * Verifica se usuário esta cadastrado e se sua senha confere.
     * 
     * @param usuario 
     * @param senha 
     * @return std::string 
     */

    std::string verifyLogin(Json::Value usuario, Json::Value senha);

    /**
     * @brief Interface de interação do backend.
     * 
     * Realiza a interação entre o frontend e o modulo de banco de dados
     * 
     * @param input 
     * @return Json::Value 
     */
    Json::Value BackendInterface(const std::string&input);

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
}
#define _JSON_MODULE
#endif // _JSON_MODULE