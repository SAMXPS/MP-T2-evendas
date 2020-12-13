#include "../headers/JsonModule.h"
#include "../headers/DatabaseModule.h"
#include "../headers/UserManager.h"
#include "../headers/ProductManager.h"

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
        return JsonModule::verifyLogin(request);
    } else if(action.compare("registerUser") == 0) {
        return JsonModule::registerUser(request);
    } else if(action.compare("verifySession") == 0) {
        return JsonModule::verifySession(request);
    } else if(action.compare("endSession") == 0) {
        return JsonModule::endSession(request);
    } else if(action.compare("getUserData") == 0) {
        return JsonModule::getUserData(request);
    } else if(action.compare("updateUserData") == 0) {  
        return JsonModule::updateUserData(request);
    } else if(action.compare("loadUserProducts") == 0) {  
        return JsonModule::loadUserProducts(request);
    } else if(action.compare("announceProduct") == 0) {  
        return JsonModule::announceProduct(request);
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

Json::Value JsonModule::verifySession(const Json::Value&request) {
    Json::Value response;
    response["status"] = "OK";
    try {
        if (request.isMember("session") && request["session"] != Json::nullValue 
            && request["session"].isMember("user") && request["session"]["user"] != Json::nullValue) {
            Json::Value user = request["session"]["user"];
            if (user != Json::nullValue && user.isMember("email") && user.isMember("password")){
                User* verify = UserManager::verifyLogin(user["email"].asString(), user["password"].asString());
                if (verify) {
                    response["valid_session"] = true;
                    response["user"] = verify->toJson();
                    return response;
                }
            }
        }
    } catch (const Json::RuntimeError&err) {
        response["status"] = "ERROR";
        response["error"] = err.what();
    } catch (const Json::LogicError&err) {
        response["status"] = "ERROR";
        response["error"] = err.what();
    }

    response["valid_session"] = false;

    return response;
}

Json::Value JsonModule::registerUser(const Json::Value&request) {
    Json::Value response;
    bool success = UserManager::registerUser(request["data"]["email"].asString(), request["data"]["name"].asString(), request["data"]["password"].asString());
    response["data"] = success ? "SUCCESS" : "FAIL";
    return response;
}

Json::Value JsonModule::verifyLogin(const Json::Value&request) {
    Json::Value response;

    User* user = UserManager::verifyLogin(request["data"]["email"].asString(),request["data"]["password"].asString());
    response["status"] = "OK";

    if (user != nullptr) {
        response["data"] = "VALID_PASSWORD";
        response["session"] = Json::Value();
        response["session"]["user"] = user->toJson();
    } else {
        response["data"] = "INVALID_PASSWORD";
    }

    return response;
}

Json::Value JsonModule::endSession(const Json::Value&request) {
    Json::Value response;

    response["status"] = "OK";
    response["session"] = "destroy";

    return response;
}

Json::Value JsonModule::getUserData(const Json::Value&request) {
    Json::Value response;
    Json::Value session_info = verifySession(request);

    if (session_info["valid_session"].asBool()) {
        response["status"] = "OK";
        int userId = std::stoi((request["data"]["id"] != Json::nullValue ? request["data"]["id"] : request["session"]["user"]["id"]).asString());
        response["id"] = userId;
        UserData* userData = UserManager::loadUserData(userId);
        response["user_data"] = userData ? userData->toJson() : Json::nullValue;
        return response;
    }

    response["status"] = "ERROR";
    response["error"] = "INVALID_SESSION";
    return response;
}


Json::Value JsonModule::updateUserData(const Json::Value&request) {
    Json::Value response;
    Json::Value session_info = verifySession(request);

    if (session_info["valid_session"].asBool()) {
        response["status"] = "OK";
        int id = request["session"]["user"]["id"].asInt();
        std::string document = request["data"]["document"].asString();
        std::string phone_number = request["data"]["phone_number"].asString();
        std::string address = request["data"]["address"].asString();
        UserData data(id, address, document, phone_number);
        UserManager::saveUserData(data);
        response["data"] = data.toJson();
        return response;
    }

    response["status"] = "ERROR";
    response["error"] = "INVALID_SESSION";
    return response;
}


Json::Value JsonModule::loadUserProducts(const Json::Value&request){
    Json::Value response;
    Json::Value session_info = verifySession(request);

    if (session_info["valid_session"].asBool()) {
        response["status"] = "OK";
        int userId = std::stoi((request["data"]["id"] != Json::nullValue ? request["data"]["id"] : request["session"]["user"]["id"]).asString());
        response["id"] = userId;
        Json::Value list = Json::arrayValue;
        for (auto product : ProductManager::loadUserProducts(userId)) {
            list.append(product.toJson());
        } 
        response["products"] = list;
        return response;
    }

    response["status"] = "ERROR";
    response["error"] = "INVALID_SESSION";
    return response;
}

Json::Value JsonModule::announceProduct(const Json::Value&request) {
    Json::Value response;
    Json::Value session_info = verifySession(request);

    if (session_info["valid_session"].asBool()) {
        response["status"] = "OK";

        int userId = std::stoi(request["session"]["user"]["id"].asString());
        std::string name = request["data"]["name"].asString();
        std::string description = request["data"]["description"].asString();
        float price = std::stof(request["data"]["price"].asString());
        std::string category = request["data"]["category"].asString();
        std::string image = request["data"]["image"].asString();

        response["success"] = ProductManager::addProduct(Product(
            -1, 
            name, 
            description, 
            price, 
            category, 
            image, 
            userId
        ));

        return response;
    }

    response["status"] = "ERROR";
    response["error"] = "INVALID_SESSION";
    return response;
}