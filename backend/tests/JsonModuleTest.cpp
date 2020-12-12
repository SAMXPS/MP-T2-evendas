#include "JsonModuleTest.hpp"
#include <sstream>
#include <iostream>

TEST_F(JsonModuleTest, verifyLogin) {
    std::stringstream stream;
    Json::Value request;
    request["data"]["action"] = "verifyLogin";
    request["data"]["email"] = "statictest@test";
    request["data"]["password"] = "statictest@test";
    stream << request;

    Json::Value response = JsonModule::BackendInterface(stream);
    GTEST_ASSERT_NE(Json::nullValue, response.type());
    GTEST_ASSERT_EQ(true, response.isMember("status"));
    GTEST_ASSERT_EQ("OK", response["status"].asString());
    GTEST_ASSERT_EQ(true, response.isMember("data"));
    GTEST_ASSERT_EQ("VALID_PASSWORD", response["data"].asString());
    GTEST_ASSERT_EQ(true, response.isMember("session"));
    GTEST_ASSERT_NE(Json::nullValue, response["session"].type());
    GTEST_ASSERT_EQ(true, response["session"].isMember("user"));
    GTEST_ASSERT_EQ("statictest@test", response["session"]["user"]["email"].asString());
    GTEST_ASSERT_EQ("statictest@test", response["session"]["user"]["password"].asString());
    GTEST_ASSERT_EQ("statictest@test", response["session"]["user"]["name"].asString());
}