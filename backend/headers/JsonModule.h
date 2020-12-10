#ifndef _JSON_MODULE
#include <istream>
#include <jsoncpp/json/json.h>

/**
 * @brief Modulo que processa as requisições e respostas ao cliente
 * 
 */
namespace JsonModule{

    /**
     * @brief Interface de interação do backend.
     * 
     * Realiza a interação entre o frontend e o modulo de banco de dados
     * 
     * @param input 
     * @return Json::Value 
     */
    Json::Value BackendInterface(std::istream&input);

}

#define _JSON_MODULE
#endif // _JSON_MODULE