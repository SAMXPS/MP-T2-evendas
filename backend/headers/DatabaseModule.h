#ifndef _DATABASE_MODULE
#define _DATABASE_MODULE
#include <mysql/mysql.h>
#include <list>
#include <map>
#include <string>

typedef std::map<std::string, std::string> DatabaseRow;
typedef std::list<DatabaseRow> DatabaseResult;

class DatabaseError {
    private:
        std::string message;
    public:
        DatabaseError(const std::string&error) {
            this->message = error;
        }
        std::string what() {
            return message;
        }
};

class DatabaseModule {
    private:
        static DatabaseModule* instance;
        MYSQL connection;
        MYSQL_RES *result;
        bool connected = false;

        bool connect();
        bool disconnect();
        void throwLastError();

        DatabaseModule() {};

        ~DatabaseModule();

    public:
        static DatabaseModule* getInstance();
        DatabaseResult* executeQuery(const std::string&query);
};

#endif//_DATABASE_MODULE