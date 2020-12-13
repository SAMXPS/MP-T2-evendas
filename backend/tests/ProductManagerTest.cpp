#include "ProductManagerTest.hpp"
#include <iostream>

TEST_F(ProductManagerTest, addProduct) {
    Product product_test(-1, name, description, price, category,imagePath, sellerId);
    GTEST_ASSERT_EQ(true, ProductManager::addProduct(product_test));
}

TEST_F(ProductManagerTest, loadUserProducts) {
    std::list<Product> products = ProductManager::loadUserProducts(sellerId);
    GTEST_ASSERT_GT(products.size(), 0);
    Product last = products.back();
    GTEST_ASSERT_EQ(name, last.getName());
    GTEST_ASSERT_EQ(description, last.getDescription());
    GTEST_ASSERT_EQ(price, last.getPrice());
    GTEST_ASSERT_EQ(category, last.getCategory());
    GTEST_ASSERT_EQ(imagePath, last.getImagePath());
}

TEST_F(ProductManagerTest, updateProduct) {
    Product product_test = ProductManager::loadUserProducts(sellerId).back();
    std::string new_name = "new_name_test";
    std::string new_description = "new brief test description";
    product_test.setName(new_name);
    product_test.setDescription(new_description);
    GTEST_ASSERT_EQ(true, ProductManager::updateProduct(product_test));
    Product* loaded_product = ProductManager::loadProduct(product_test.getId());
    GTEST_ASSERT_NE(nullptr, loaded_product);
    GTEST_ASSERT_EQ(product_test.getId(), loaded_product->getId());
    GTEST_ASSERT_EQ(new_name, loaded_product->getName());
    GTEST_ASSERT_EQ(new_description, loaded_product->getDescription());
    GTEST_ASSERT_EQ(product_test.getCategory(), loaded_product->getCategory());
    GTEST_ASSERT_EQ(product_test.getPrice(), loaded_product->getPrice());
    GTEST_ASSERT_EQ(product_test.getImagePath(), loaded_product->getImagePath());
    GTEST_ASSERT_EQ(product_test.getSellerId(), loaded_product->getSellerId());
}

TEST_F(ProductManagerTest, loadProduct) {
    Product product_test = ProductManager::loadUserProducts(sellerId).back();
    Product* loaded_product = ProductManager::loadProduct(product_test.getId());
    GTEST_ASSERT_NE(nullptr, loaded_product);
    GTEST_ASSERT_EQ(product_test.getId(), loaded_product->getId());
    GTEST_ASSERT_EQ(product_test.getName(), loaded_product->getName());
    GTEST_ASSERT_EQ(product_test.getDescription(), loaded_product->getDescription());
    GTEST_ASSERT_EQ(product_test.getCategory(), loaded_product->getCategory());
    GTEST_ASSERT_EQ(product_test.getPrice(), loaded_product->getPrice());
    GTEST_ASSERT_EQ(product_test.getImagePath(), loaded_product->getImagePath());
    GTEST_ASSERT_EQ(product_test.getSellerId(), loaded_product->getSellerId());
}

TEST_F(ProductManagerTest, removeProducts) {
    for(auto product : ProductManager::loadUserProducts(sellerId)) {
        int id = product.getId();
        GTEST_ASSERT_EQ(true, ProductManager::removeProduct(id));
        GTEST_ASSERT_EQ(nullptr, ProductManager::loadProduct(id));
    }
}