#ifndef DATABASE_MODULE_TEST_HPP_INCLUDED
#define DATABASE_MODULE_TEST_HPP_INCLUDED
#include <gtest/gtest.h>
#include "../headers/DatabaseModule.h"

class DatabaseModuleTest: public ::testing::Test {
    protected:
        DatabaseModule* instance;

    public:
        DatabaseModuleTest() { 
            
        } 

        void SetUp() { 
            instance = DatabaseModule::getInstance();
        }

        void TearDown() { 
            // Código que roda depois da execução do teste
        }
};

#endif //DATABASE_MODULE_TEST_HPP_INCLUDED