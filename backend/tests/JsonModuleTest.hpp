#ifndef JSON_MODULE_TEST_HPP_INCLUDED
#define JSON_MODULE_TEST_HPP_INCLUDED
#include <gtest/gtest.h>
#include "../headers/JsonModule.h"

class JsonModuleTest: public ::testing::Test {
    public: 
        JsonModuleTest() { 
            
        } 

        void SetUp() { 
            // Código que roda antes da execução de teste
        }

        void TearDown() { 
            // Código que roda depois da execução do teste
        }
};

#endif //JSON_MODULE_TEST_HPP_INCLUDED