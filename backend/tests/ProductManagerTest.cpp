#include "ProductManagerTest.hpp"

TEST_F(ProductManagerTest, addProduct) {
    Product product_test(id, name, description, price, category,imagePath, sellerId);
    ProductManager::removeProduct(product_test.getId());
    GTEST_ASSERT_EQ(true, ProductManager::addProduct(product_test));
    GTEST_ASSERT_EQ(false, ProductManager::addProduct(product_test));
}

TEST_F(ProductManagerTest, removeProduct) {
    Product product_test(id, name, description, price, category,imagePath, sellerId);
    ProductManager::addProduct(product_test);
    GTEST_ASSERT_EQ(true, ProductManager::removeProduct(product_test.getId()));
    GTEST_ASSERT_EQ(false, ProductManager::removeProduct(product_test.getId()));
}

TEST_F(ProductManagerTest, loadProduct) {
    Product product_test(id, name, description, price, category,imagePath, sellerId);
    ProductManager::addProduct(product_test);
    Product* loaded_product = ProductManager::loadProduct(id);
    GTEST_ASSERT_EQ(product_test.getId() ,loaded_product->getId());
    GTEST_ASSERT_EQ(product_test.getName() ,loaded_product->getName());
    GTEST_ASSERT_EQ(product_test.getDescription() ,loaded_product->getDescription());
    GTEST_ASSERT_EQ(product_test.getCategory() ,loaded_product->getCategory());
    GTEST_ASSERT_EQ(product_test.getPrice(), loaded_product->getPrice());
    GTEST_ASSERT_EQ(product_test.getImagePath(), loaded_product->getImagePath());
    GTEST_ASSERT_EQ(product_test.getSellerId(), loaded_product->getSellerId());
    ProductManager::removeProduct(id);
    GTEST_ASSERT_EQ(nullptr ,ProductManager::loadProduct(id));
}

TEST_F(ProductManagerTest, updateProduct) {
    Product product_test(id, name, description, price, category,imagePath, sellerId);
    ProductManager::addProduct(product_test);
    std::string new_name = "new_name_test";
    std::string new_description = "new brief test description";
    Product new_product_test(id, new_name, new_description, price, category, imagePath, sellerId);
    GTEST_ASSERT_EQ(true, ProductManager::updateProduct(new_product_test));
}