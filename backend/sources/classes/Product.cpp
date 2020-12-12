#include "../../headers/classes/Product.h"

Product::Product(int id, const std::string&name, const std::string&description, float price, const std::string&category,
const std::string&imagePath, int sellerId) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
    this->category = category;
    this->imagePath = imagePath;
    this->sellerId = sellerId;
}    

int Product::getId() const {
    return this->id;
}

std::string Product::getName() const {
    return this->name;
}

float Product::getPrice() const {
    return this->price;
}

std::string Product::getCategory() const {
    return this->category;
}
std::string Product::getImagePath() const {
    return this->imagePath;
}

int Product::getSellerId() const {
    return this->sellerId;
}

Json::Value Product::toJson() {
    Json::Value product;
    product["id"] = id;
    product["name"] = name;
    product["price"] = price;
    product["category"] = category;
    product["description"] = description;
    product["imagePath"] = imagePath;
    product["sellerId"] = sellerId;
    return product;
}