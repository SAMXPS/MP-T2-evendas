#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Classe que contem dados do usuario
 */
class User {
    private:
        int id;
        std::string name;
        std::string email;
        std::string password;

    public:
        User(int id, const std::string&name,const std::string&email,const std::string&password);

        int getId() const;
        std::string getName() const;
        std::string getEmail() const;
        std::string getPassword() const;

        bool verifyPassword(const std::string&typedPassword) const;

        Json::Value toJson();
};

#endif//USER_H_INCLUDED