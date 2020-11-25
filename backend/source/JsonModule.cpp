#include "../headers/JsonModule.h"
#include <iostream>

using namespace JsonModule;

std::string JsonModule::verifyLogin(Json::Value usuario, Json::Value senha) {
    if(usuario.compare("teste@teste.com") == 0 && senha.compare("teste") == 0) {
        return "VALID_PASSWORD";
    }
    return "INVALID_PASSWORD";
}

std::string JsonModule::registerUser(Json::Value nome, Json::Value senha, Json::Value email) {
    return "OK";
}

Json::Value JsonModule::BackendInterface(const std::string&input) {
    Json::Value request;
    std::string chave;
    Json::Value response;
    Json::Reader reader;

    bool parseSuccess = reader.parse(input, request); // Leitura do pedido em json, na entrada padrão.
    if (!parseSuccess) {
        response["status"] = "ERROR";
        response["error"] = "INVALID_JSON";
        response["error_message"] = reader.getFormattedErrorMessages();
        
        return response;
    }

    // processa a ação da requisição
    std::string action = request["data"].get("action","vazio").asString();
    
    if (action.compare("verifyLogin") == 0) { 
        // Verifica a senha do usuario.
        response["data"] = verifyLogin(request["data"]["email"], request["data"]["password"]);
    } else if(action.compare("registerUser") == 0) {  // cadastra novo cliente conforme informações passadas.  
        response["data"] = registerUser(request["data"]["name"], request["data"]["password"], request["data"]["email"]);
    } else if(action.compare("carregarProduto") == 0) {  
        // carrega um produto de um anunciante.

    } else if(action.compare("listarProdutos") == 0) {  
        // lista os produtos conforme os parametros passados.

    } else if(action.compare("buscarVendedor") == 0) {  
        // busca dados de determinado vendedor.

    } else if(action.compare("buscarUsuario") == 0) {  
        // busca dados de determinado usuario.

    } else {
        // acao nao encontrada. um erro eh retornado.
        response["status"] = "ERROR";
        response["error"] = "INVALID_ACTION";
        return response;
    }
    
    response["status"] = "OK";
    response["session"] = request["session"];

    return response;
}