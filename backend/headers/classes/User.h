#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>

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
        User(int id, const std::string&name,const std::string&email,const std::string&password) ;

        int getId();
        std::string getName();
        std::string getEmail();
        std::string getPassword();

        bool verifyPassword(const std::string&typedPassword);
};

#endif//USER_H_INCLUDED