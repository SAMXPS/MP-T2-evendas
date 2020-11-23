#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include "../headers/test.h"

std::string verifica_senha(Json::Value usuario, Json::Value senha) {
    if(usuario.compare("samuel")&&senha.compare("12345")) {
        return "123456789";
    }
}

int main() {
    Json::Value request;
    Json::Value response;
    Json::Reader reader;
    Json::FastWriter writer;

    bool error = reader.parse(std::cin, request); // Leitura do pedido em json, na entrada padrão.
    response["status"] = "FALSE";
    if (!error) {
        std::cout << "Error: " << reader.getFormattedErrorMessages();
        response["status"] = "FALSE";
    }
    

    // processa a ação da requisição
    std::string action = writer.write(request["action"]);
    std::string chave;
    if(action.compare("verificarSenha")) { // Verificar senha
       chave = verifica_senha(request["usuario"], request["senha"]);
       response["status"] = "OK";
    }

    
    response["session"] = request["session"];
    response["data"]["chave_padrao"] = chave;
    std::cout << response;
    return 0;
}