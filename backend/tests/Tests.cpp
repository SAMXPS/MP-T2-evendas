#include <gtest/gtest.h>
#include "DatabaseModuleTest.hpp"
#include "JsonModuleTest.hpp"
#include "UserManagerTest.hpp"

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}