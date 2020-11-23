#include "../headers/JsonModule.h"
#include <iostream>

using namespace JsonModule;

std::string JsonModule::verifica_senha(Json::Value usuario, Json::Value senha) {
    if(usuario.compare("samuel") == 0 && senha.compare("12345") == 0) {
        return "123456789";
    }
}

Json::Value JsonModule::Get(const std::string&input) {
    Json::Value request;
    std::string chave;
    Json::Value response;
    Json::Reader reader;

    bool error = reader.parse(input, request); // Leitura do pedido em json, na entrada padrão.
    if (!error) {
        std::cout << "Error: " << reader.getFormattedErrorMessages();
        response["status"] = "FALSE";
    }

    // processa a ação da requisição
    std::string action = request["data"].get("action","vazio").asString();
    
    if(action.compare("verificarSenha") == 0) { // efetua verificção de senha
        chave = verifica_senha(request["data"]["usuario"], request["data"]["senha"]);
        response["status"] = "OK";

    } else if(action.compare("cadastrarCliente") == 0) {  // cadastra novo cliente conforme informações passadas.

        response["status"] = "OK";
    } else if(action.compare("carregarProduto") == 0) {  // carrega um produto de um anunciante.

        response["status"] = "OK";
    } else if(action.compare("listarProdutos") == 0) {  // lista os produtos conforme os parametros passados.

        response["status"] = "OK";
    } else if(action.compare("buscarVendedor") == 0) {  // busca dados de determinado vendedor.

        response["status"] = "OK";
    } else if(action.compare("buscarUsuario") == 0) {  // busca dados de determinado usuario.

        response["status"] = "OK";
    }
    
    response["session"] = request["session"];
    response["data"]["chave_padrao"] = chave;

    return response;
}