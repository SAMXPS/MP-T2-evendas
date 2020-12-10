#ifndef _DATABASE_MODULE
#define _DATABASE_MODULE
#include <mysql/mysql.h>
#include <list>
#include <map>
#include <string>

/**
 * @brief Estrutura de dados que representa linha de resultado de banco de dados.
*/
typedef std::map<std::string, std::string> DatabaseRow;

/**
 * @brief Estrutura de dados que representa resultado de banco de dados.
*/
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

/**
 * @brief Módulo de conexão ao banco de dados MySQL.
*/
class DatabaseModule {
    private:
        static DatabaseModule* instance;
        MYSQL connection;
        MYSQL_RES *result;
        bool connected = false;

        /**
         * @brief Conecta no banco de dados MySQL.
        */
        bool connect();

        /**
         * @brief Desconecta do banco de dados MySQL.
        */
        bool disconnect();

        /***
         * @brief Função interna para lançar última exceção/erro que ocorreu no banco de dados.
         */
        void throwLastError();

        /**
         * @brief Construtor privado: Singleton.
        */
        DatabaseModule() {};

        ~DatabaseModule();

    public:

        /**
         * @brief Retorna uma instancia do módulo, usando design pattern Singleton.
        */
        static DatabaseModule* getInstance();

        /**
         * 
         * @brief Envia requisição ao banco de dados MySQL.
         * 
         * @param query Comando SQL a ser executado.
         * 
         * @return DatabaseResult* Ponteiro para resultado de banco de dados. 
         * Pode ser nulo em caso de erro.
         * 
        */
        DatabaseResult* executeQuery(const std::string&query);
};

#endif//_DATABASE_MODULE