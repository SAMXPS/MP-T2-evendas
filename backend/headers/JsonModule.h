#ifndef _JSON_MODULE

/**
 * @brief Modulo que processa as requisições e respostas ao cliente
 * 
 */
namespace JsonModule{
    /**
     * @brief verifica usuário e senha
     * 
     * Verifica se usuário esta cadastrado e se sua senha confere.
     * 
     * @param usuario 
     * @param senha 
     * @return std::string 
     */

    std::string verifica_senha(Json::Value usuario, Json::Value senha);
    Json::Value Get();
}
#define _JSON_MODULE
#endif // _JSON_MODULE