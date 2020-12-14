// Copyright 2020 Samuel James, Leonam Gomes
#include "../headers/DatabaseModule.h"
#include <iostream>

DatabaseModule* DatabaseModule::instance = nullptr;

DatabaseModule::~DatabaseModule() {
     try {
          disconnect();
     } catch(...) { }
}

DatabaseModule* DatabaseModule::getInstance() {
     if (instance == nullptr)
          instance = new DatabaseModule();
     return instance;
}

bool DatabaseModule::connect() {
     mysql_init(&this->connection);
     mysql_options(&this->connection, MYSQL_SET_CHARSET_NAME, "utf8");
     mysql_options(&this->connection, MYSQL_INIT_COMMAND, "SET NAMES utf8");

     if (mysql_real_connect(&this->connection, "127.0.0.1", "evendas",
          "WgAC95xFZHcBdJPH", "evendas", 0, NULL, 0)) {
          this->connected = true;
          return true;
     } else {
          this->connected = false;
          throwLastError();
          return false;
     }
}

bool DatabaseModule::disconnect() {
     mysql_close(&this->connection);
     this->connected = false;
}

void DatabaseModule::throwLastError() {
     throw DatabaseError(
          "Erro " + std::to_string(mysql_errno(&this->connection))
          + ": " + mysql_error(&this->connection));
}

DatabaseResult* DatabaseModule::executeQuery(const std::string&query) {
     if (!this->connected)
     if (!this->connect()) return nullptr;

     if (mysql_query(&this->connection, query.c_str())) {
          throwLastError();
     }

     DatabaseResult* resultado = new DatabaseResult();
     result = mysql_store_result(&this->connection);

     if (result) {
          int num_fields = mysql_num_fields(result);

          MYSQL_FIELD *field;
          std::string fields[num_fields];

          for (int i = 0; field = mysql_fetch_field(result); i++) {
               fields[i] = field->name;
          }

          MYSQL_ROW _row;

          while ((_row = mysql_fetch_row(result))) {
               DatabaseRow row;
               for (int i = 0; i < num_fields; i++) {
                    row[fields[i]] = _row[i] ? _row[i] : "NULL";
               }
               resultado->push_back(row);
          }

          mysql_free_result(result);
     }

     return resultado;
}
