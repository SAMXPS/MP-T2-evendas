#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include "../headers/test.h"

std::string verifica_senha(Json::Value usuario, Json::Value senha) {
    if(usuario.compare("samuel") == 0 && senha.compare("12345") == 0) {
        return "123456789";
    }
}

int main() {
    Json::Value request;
    std::string chave;
    Json::Value response;
    Json::Reader reader;

    bool error = reader.parse(std::cin, request); // Leitura do pedido em json, na entrada padrão.
    if (!error) {
        std::cout << "Error: " << reader.getFormattedErrorMessages();
        response["status"] = "FALSE";
    }

    // processa a ação da requisição
    std::string action = request["data"].get("action","vazio").asString();
    
    if(action.compare("verificarSenha") == 0) { // efetua verificção de senha
       chave = verifica_senha(request["data"]["usuario"], request["data"]["senha"]);
       response["status"] = "OK";
    }

    response["session"] = request["session"];
    response["data"]["chave_padrao"] = chave;
    std::cout << response;
    return 0;
}