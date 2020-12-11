#include "../headers/JsonModule.h"
#include "../headers/DatabaseModule.h"
#include "../headers/UserManager.h"

using namespace JsonModule;
using namespace UserManager;

Json::Value JsonModule::BackendInterface(std::istream&input) {  
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
        response["data"] = verifyLogin(request["data"]["email"].asString(),request["data"]["password"].asString());
    } else if(action.compare("registerUser") == 0) {  // cadastra novo cliente conforme informações passadas.  
        response["data"] = registerUser(request["data"]["email"].asString(), request["data"]["name"].asString(), request["data"]["password"].asString());
    } else if(action.compare("loadItem") == 0) {  
        // carrega um produto de um anunciante.

    } else if(action.compare("ListItem") == 0) {  
        // lista os produtos conforme os parametros passados.

    } else if(action.compare("searchSeller") == 0) {  
        // busca dados de determinado vendedor.

    } else if(action.compare("searchClient") == 0) {  
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