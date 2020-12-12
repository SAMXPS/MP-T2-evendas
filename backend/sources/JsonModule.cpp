#include "../headers/JsonModule.h"
#include "../headers/DatabaseModule.h"
#include "../headers/UserManager.h"

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

    std::string action = request["data"].get("action","vazio").asString();
    
    if (action.compare("verifyLogin") == 0) {
        User* user = UserManager::verifyLogin(request["data"]["email"].asString(),request["data"]["password"].asString());
        response["data"] = user == NULL ? "INVALID_PASSWORD" : "VALID_PASSWORD";
    } else if(action.compare("registerUser") == 0) {
        bool success = UserManager::registerUser(request["data"]["email"].asString(), request["data"]["name"].asString(), request["data"]["password"].asString());
        response["data"] = success ? "SUCCESS" : "FAIL";
    } else if(action.compare("loadItem") == 0) {  

    } else if(action.compare("ListItem") == 0) {  

    } else if(action.compare("searchSeller") == 0) {  

    } else if(action.compare("searchClient") == 0) {  

    } else {
        response["status"] = "ERROR";
        response["error"] = "INVALID_ACTION";
        return response;
    }
    
    response["status"] = "OK";
    response["session"] = request["session"];

    return response;
}