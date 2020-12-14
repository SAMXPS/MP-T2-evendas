#ifndef USER_DATA_H_INCLUDED
#define USER_DATA_H_INCLUDED
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Classe que contem todos os dados do usuario
 */
class UserData {
    private:
        int id;
        std::string address;
        std::string document;
        std::string phoneNumber;

    public:
        /**
         * @brief Controi um novo objeto UserData
         * 
         * @param id 
         * @param address 
         * @param document 
         * @param phoneNumber 
         */
        UserData(int id, const std::string&address,const std::string&document,const std::string&phoneNumber) ;

        /**
         * @brief Pega o id do usuário
         * 
         * Retorna o Id do usuário
         * 
         * @return int 
         */
        int getId() const;

        /**
         * @brief Pega o endereço do usuário
         * 
         * retorna o endereço de um usuário
         * 
         * @return std::string 
         */
        std::string getAddress() const;

        /**
         * @brief Pega o documento do usuário
         * 
         * Retorna o documento de um usuário, ex: cpf, rg
         * 
         * @return std::string 
         */
        std::string getDocument() const;

        /**
         * @brief Pega o telefone de um usuário
         * 
         * Retorna o número de telefone de um usuário
         * 
         * @return std::string 
         */
        std::string getPhoneNumber() const;

        /**
         * @brief Transforma os dados do usuário em Json
         * 
         * Gera e retorna os dados do usuário em formado Json.
         * 
         * @return Json::Value 
         */
        Json::Value toJson();
};

#endif//USER_DATA_H_INCLUDED