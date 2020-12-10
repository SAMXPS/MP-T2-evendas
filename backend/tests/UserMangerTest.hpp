#ifndef USER_MANAGER_TEST_HPP_INCLUDED
#define USER_MANAGER_TEST_HPP_INCLUDED
#include <gtest/gtest.h>
#include "../headers/UserManager.h"

class UserManagerTest: public ::testing::Test {
    public: 
        UserManagerTest() { 
        } 

        void SetUp() { 
            // Código que roda antes da execução de teste
        }

        void TearDown() { 
            // Código que roda depois da execução do teste
        }
};

#endif //USER_MANAGER_TEST_HPP_INCLUDED