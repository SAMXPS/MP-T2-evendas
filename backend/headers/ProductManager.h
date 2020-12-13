#ifndef PRODUCT_MANAGER_H_INCLUDED
#define PRODUCT_MANAGER_H_INCLUDED
#include "classes/Product.h"
#include <list>
#include <string>

class ProductManager {
    public:
        /**
         * @brief Carrega produto do banco de dados.
         * 
         * retorna ponteiro de um produto, ou retorna null se o produto não existir.
         * 
         * @param productId 
         * @return Product* 
         */
        static Product* loadProduct(int productId);

        /**
         * @brief Retorna lista de produtos de um usuario.
         * 
         * Retorna uma lista de produtos de um usuario.
         * 
         * @param sellerid 
         * @return ProductList 
         */
        static std::list<Product> loadUserProducts(int sellerid);

        /**
         * @brief Adiciona um produto ao banco de dados.
         * 
         * Adiciona produto no banco de dados e retorna true
         * Caso não seja possivel adicionar retorna false
         * 
         * @param product 
         * @return true
         * @return false 
         */
        static bool addProduct(const Product&product);

        /**
         * @brief Remove um produto do banco de dados
         * 
         * Remove um produto do banco de dados e retorna true caso possivel
         * e retorna false caso não seja possivel
         * 
         * @param productId 
         * @return true 
         * @return false 
         */
        static bool removeProduct(int productId);

        /**
         * @brief Atualiza um produto
         * 
         * Atualiza um produto e retorna true
         * Caso o produto não exista retorna false
         * 
         * @param productId 
         * @return true 
         * @return false 
         */
        static bool updateProduct(const Product&product);

        /**
         * @brief Lista as categorias de produtos
         * 
         * Lista as categorias de produtos do banco de dados.
         * 
         * @return std::list<std::string> 
         */
        static std::list<std::string> listCategory();

        private:
};

#endif // PRODUCT_MANAGER_H_INCLUDED