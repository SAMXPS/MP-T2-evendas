#include "DatabaseModuleTest.hpp"

TEST_F(DatabaseModuleTest, databaseConnect) {
    DatabaseResult* result = instance->executeQuery("SELECT CURRENT_TIMESTAMP");
    GTEST_ASSERT_NE(nullptr, result);
    GTEST_ASSERT_EQ(1, result->size());
    GTEST_ASSERT_NE(nullptr, result->front()["CURRENT_TIMESTAMP"]);
}
