#ifndef USER_DATA_H_INCLUDED
#define USER_DATA_H_INCLUDED
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Classe que contem dados do usuario
 */
class UserData {
    private:
        int id;
        std::string address;
        std::string document;
        std::string phoneNumber;

    public:
        UserData(int id, const std::string&address,const std::string&document,const std::string&phoneNumber) ;

        int getId() const;
        std::string getAddress() const;
        std::string getDocument() const;
        std::string getPhoneNumber() const;

        Json::Value toJson();
};

#endif//USER_DATA_H_INCLUDED