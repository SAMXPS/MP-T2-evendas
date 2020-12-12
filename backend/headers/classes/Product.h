#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <string>

/**
 * @brief Classe que contem dados do produto
 */
class Product {
    private:
        std::string name;
        float price;
        std::string category;
        std::string longDescription;
        std::string imagePath;
        std::string seller;

    public:
        Product(const std::string&name, float price,const std::string&category,const std::string&longDescription
        , const std::string&imagePath, const std::string&seller);

        std::string getName();
        float getPrice();
        std::string getCategory();
        std::string getLongDescription();
        std::string getImagePath();
        std::string getSeller();
};

#endif // PRODUCT_H_INCLUDED