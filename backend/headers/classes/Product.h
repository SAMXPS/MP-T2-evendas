#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <string>
#include <jsoncpp/json/json.h>

/**
 * @brief Classe que contem dados do produto
 */
class Product {
    private:

        int id;
        std::string name;
        std::string description;
        float price;
        std::string category;
        std::string imagePath;
        int sellerId;

    public:
        Product(int id, const std::string&name, const std::string&description, float price, const std::string&category,
        const std::string&imagePath, int sellerId);

        int getId() const;
        std::string getName() const;
        float getPrice() const;
        std::string getCategory() const;
        std::string getDescription() const;
        std::string getImagePath() const;
        int getSellerId() const;

        Json::Value toJson();
};

#endif // PRODUCT_H_INCLUDED