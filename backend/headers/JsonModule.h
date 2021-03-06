#ifndef JSON_MODULE_H_INCLUDED
#define JSON_MODULE_H_INCLUDED
#include <istream>
#include <jsoncpp/json/json.h>

/**
 * @brief Modulo que processa as requisições e respostas ao cliente
 * 
 */
class JsonModule {
    private:
        static Json::Value verifySession(const Json::Value&request);
        static Json::Value verifyLogin(const Json::Value&request);
        static Json::Value registerUser(const Json::Value&request);
        static Json::Value endSession(const Json::Value&request);
        static Json::Value getUserData(const Json::Value&request);
        static Json::Value updateUserData(const Json::Value&request);
        static Json::Value loadUserProducts(const Json::Value&request);
        static Json::Value announceProduct(const Json::Value&request);
        static Json::Value deleteProduct(const Json::Value&request);
        static Json::Value loadCategories(const Json::Value&request);
        static Json::Value loadCategoryProducts(const Json::Value&request);
       
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