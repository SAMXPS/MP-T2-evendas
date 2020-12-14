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
        /**
         * @brief Controi um novo objeto Product
         * 
         * @param id 
         * @param name 
         * @param description 
         * @param price 
         * @param category 
         * @param imagePath 
         * @param sellerId 
         */
        Product(int id, const std::string&name, const std::string&description, float price, const std::string&category,
        const std::string&imagePath, int sellerId);

        /**
         * @brief Pega o id de um produto
         * 
         * Retorna um Id de um produto
         * 
         * @return int 
         */
        int getId() const;
        /**
         * @brief Pega o nome de um produto
         * 
         * Retorna o nome do produto
         * 
         * @return std::string 
         */
        std::string getName() const;

        /**
         * @brief Pega o preço de um produto
         * 
         * Retorna o valor de um produto.
         * 
         * @return float 
         */
        float getPrice() const;

        /**
         * @brief Pega a categoria de um produto
         * 
         * Retorna a categoria do produto
         * 
         * @return std::string 
         */
        std::string getCategory() const;

        /**
         * @brief Pega a descrição de um produto
         * 
         * Retorna a descrição de um produto
         * 
         * @return std::string 
         */
        std::string getDescription() const;

        /**
         * @brief Pega o caminho da imagem do produto
         * 
         * Retorna um path para a imagem de um produto
         * 
         * @return std::string 
         */
        std::string getImagePath() const;

        /**
         * @brief Pega o id do vendedor do produto
         * 
         * Retorna o id do vendedor do produto
         * 
         * @return int 
         */
        int getSellerId() const;
        
        /**
         * @brief Altera o nome do produto
         * 
         * Estabelece um nome nome para o produto
         * 
         * @param name 
         */
        void setName(std::string name);

        /**
         * @brief Altera o preço do produto
         * 
         * Estabelece um novovalor para o produto
         * 
         * @param price 
         */
        void setPrice(float price);

        /**
         * @brief Altera a categoria do produto
         * 
         * Estabelece uma nova categoria para o produto
         * 
         * @param category 
         */
        void setCategory(std::string category);

        /**
         * @brief Altera a descrição do produto
         * 
         * Estabelece uma nova descrição para o produto
         * 
         * @param description 
         */
        void setDescription(std::string description);

        /**
         * @brief Altera o caminho da imagem do produto
         * 
         * Estabelece um novo caminho para a imagem o produto
         * 
         * @param imagePath 
         */
        void setImagePath(std::string imagePath);

        Json::Value toJson();
};

#endif // PRODUCT_H_INCLUDED