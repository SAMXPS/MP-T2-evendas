#include "ProductManagerTest.hpp"

TEST_F(ProductManagerTest, addProduct) {
    Product product_test(id, name, description, price, category,imagePath, sellerId);
    ProductManager::removeProduct(product_test.getId());
    GTEST_ASSERT_EQ(true, ProductManager::addProduct(product_test));
    GTEST_ASSERT_EQ(false, ProductManager::addProduct(product_test));
}

