#ifndef USER_MANAGER_TEST_HPP_INCLUDED
#define USER_MANAGER_TEST_HPP_INCLUDED
#include "../headers/UserManager.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

class UserManagerTest: public ::testing::Test {
    protected:
        const std::string test_name = "Test User";
        const std::string wrong_test_email = "wrong_teste@teste.com";
        const std::string test_email = "teste@teste.com";
        const std::string test_password = "123456";
        const std::string wrong_password = "654321";

    public: 
        UserManagerTest() { 
            
        } 

        void SetUp() {

        }

        void TearDown() {

        }
};

#endif //USER_MANAGER_TEST_HPP_INCLUDED