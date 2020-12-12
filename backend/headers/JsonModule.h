#ifndef JSON_MODULE_H_INCLUDED
#define JSON_MODULE_H_INCLUDED
#include <istream>
#include <jsoncpp/json/json.h>

/**
 * @brief Modulo que processa as requisições e respostas ao cliente
 * 
 */
class JsonModule{
    public:
        /**
         * @brief Interface de interação do backend.
         * 
         * Realiza a interação entre o frontend e o modulo de banco de dados
         * 
         * @param input 
         * @return Json::Value 
         */
        static Json::Value BackendInterface(std::istream&input);
};

#endif//JSON_MODULE_H_INCLUDED