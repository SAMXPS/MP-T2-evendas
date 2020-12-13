#include "../headers/ProductManager.h"
#include "../headers/DatabaseModule.h"
#include <iostream>

Product* ProductManager::loadProduct(int productId) {
    DatabaseResult* result;
    try {
        result  = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `products` WHERE `ID` = '" + std::to_string(productId) + "'");

        if (result != nullptr && result->size() > 0) {
            auto element = result->front();
            return new Product(std::stoi(element["ID"]), element["NAME"], element["DESCRIPTION"], std::stof(element["PRICE"]), element["CATEGORY"],
            element["IMAGE"], std::stoi(element["SELLER_ID"]));
        }
    }
    catch(const DatabaseError&err) { }

    return nullptr;
}

std::list<Product> ProductManager::loadUserProducts(int sellerId) {
    std::list<Product> list;

    DatabaseResult* result;
    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT * FROM `products` WHERE `SELLER_ID` = '" + std::to_string(sellerId) + "'");
    } catch (const DatabaseError&error) { }

    // Verificando se o resultado existe
    if (result)
        for (auto item : *result) {
            try {
                int id = std::stoi(item["ID"]);
                std::string name = item["NAME"];
                std::string description  = item["DESCRIPTION"];
                float price = std::stof(item["PRICE"]);
                std::string category = item["CATEGORY"];
                std::string imagePath = item["IMAGE"];
                int sellerId = std::stoi(item["SELLER_ID"]);

                list.push_back(Product(
                    id, 
                    name, 
                    description, 
                    price, 
                    category, 
                    imagePath, 
                    sellerId
                ));
            }
            catch(const DatabaseError&err) { }
        }
    return list;
};

bool ProductManager::addProduct(const Product&product) {
    DatabaseResult* result;
    try {
        result = DatabaseModule::getInstance()->executeQuery("INSERT INTO `products`(`ID`, `NAME`, `DESCRIPTION`, `PRICE`, `CATEGORY`, `IMAGE`, `SELLER_ID`) VALUES (NULL,'" + product.getName() + "', '" + product.getDescription() + "', '" + std::to_string(product.getPrice()) + "', '" + product.getCategory() + "', '" + product.getImagePath() + "', '" + std::to_string(product.getSellerId()) +"')");
        return true;
    } catch (const DatabaseError&err) { }
    return false;
}

bool ProductManager::removeProduct(int productId) {
    try {
        if (loadProduct(productId) != NULL) {
            std::string _id = std::to_string(productId);
            DatabaseModule::getInstance()->executeQuery("DELETE FROM `products` WHERE `ID` = '" + _id + "'");
            return true;
        } 
    } catch (const DatabaseError&err) { }

    return false;
};

bool ProductManager::updateProduct(const Product&product) {
    try {
        std::string _id = std::to_string(product.getId());
        std::string newName = product.getName();
        std::string newDiscription = product.getDescription();
        std::string newPrice = std::to_string(product.getPrice());
        std::string newCategory = product.getCategory();
        std::string newImage = product.getImagePath();
        std::string newSellerId = std::to_string(product.getSellerId());

        DatabaseModule::getInstance()->executeQuery("UPDATE `products` SET `NAME`='" + newName + "', `DESCRIPTION`='" + newDiscription + "',`PRICE`='" + newPrice + "',`CATEGORY`='" + newCategory + "', `IMAGE`='" + newImage + "', `SELLER_ID`='" + newSellerId + "' WHERE `ID`= '" + _id + "'");

        return true;
    }
    catch(const DatabaseError&err) { }

    return false;
}

std::list<std::string> ProductManager::listCategory() {
    DatabaseResult* result;
    std::list<std::string> list;
    try {
        result = DatabaseModule::getInstance()->executeQuery("SELECT CATEGORY FROM `products` GROUP BY CATEGORY");
    } catch (const DatabaseError&error) { }

    if(result != nullptr && result->size() > 0) 
        for (auto item : *result) {
            try {
                list.push_back(item["CATEGORY"]);
            }
            catch(const DatabaseError&err) {}
        }
    return list;
}