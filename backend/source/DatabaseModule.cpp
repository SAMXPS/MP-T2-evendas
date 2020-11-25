#include <iostream>
#include <string>
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

bool conectarBanco(){
    static char *opt_host_name = "190.115.198.19"; //Nome do Servidor (default - localhost)
    static char *opt_user_name = "evendas"; //Nome do Usuário
    static char *opt_password = "WgAC95xFZHcBdJPH"; //Senha
    static unsigned int opt_port_num = 3306; //Numero da Porta 
    static char *opt_socket_name = NULL; //Numero do socket
    static char *opt_db_name = "evendas"; //Nome do Banco de dados
    static unsigned int opt_flags = 0; //Status da conexao
    MYSQL *conn; //Ponteiro para conexão
    MYSQL_RES *res; //Ponteiro dos Resultados
    MYSQL_ROQ roq; //Linha
    setlocale(LC_ALL, "Portuguese");

    conn=mysql_init(NULL);
    mysql_real_connect(conn,opt_host_name,opt_password,opt_db_name,
    opt_port_num,opt_socket_name,opt_flags);
}

bool desconectarBanco(){

}

bool consultarBanco(){
    SQL="select into usuarios(nome,endereco,email,senha) values ("'+nome+'","'+endereco+'","'+email+'","'+senha+'");";
}

bool inserirBanco(){


    if(mysql_query(conn,SQL)){
        exit(1);
    }
}

bool inserirBancoUsuarios(nome,endereco,email,senha){
    SQL="insert into usuarios(nome,endereco,email,senha) values ("'+nome+'","'+endereco+'","'+email+'","'+senha+'");";
}

bool atualizarBancoUsuarios(){
    SQL="update into usuarios(nome,endereco,email,senha) values ("'+nome+'","'+endereco+'","'+email+'","'+senha+'");";
}

bool removerBanco(email){

}