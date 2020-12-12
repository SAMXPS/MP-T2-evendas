#ifndef PRODUCT_MANAGER_TEST_HPP_INCLUDED
#define PRODUCT_MANAGER_TEST_HPP_INCLUDED
#include "../headers/ProductManager.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

class ProductManagerTest: public ::testing::Test {
    protected:
            const int id = 31;
            const std::string name = "Test product";
            const std::string description = "A brief descrition";
            const float price = 0.12345;
            const std::string category = "teste";
            const std::string imagePath = "/teste/t";
            const int sellerId = 31;
            
    public: 
        ProductManagerTest() { 

        } 

        void SetUp() { 
            
        }

        void TearDown() { 

        }
};

#endif // PRODUCT_MANAGER_TEST_HPP_INCLUDED