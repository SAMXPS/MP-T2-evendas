#include "UserMangerTest.hpp"

TEST_F(UserManagerTest, registerUser) {
    Json::Value nome = "nome_teste";
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    GTEST_ASSERT_EQ("SUCCESS", UserManager::registerUser(email, nome, senha));
}

TEST_F(UserManagerTest, verifyLogin) {
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    GTEST_ASSERT_EQ("VALID_PASSWORD", UserManager::verifyLogin(email, senha));
    senha = "11111";
    GTEST_ASSERT_EQ("INVALID_PASSWORD", UserManager::verifyLogin(email, senha));
    email = "wrongteste@teste.com";
    GTEST_ASSERT_EQ("UNREGISTERED_USER", UserManager::verifyLogin(email, senha));
}

TEST_F(UserManagerTest, removeUser) {
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    GTEST_ASSERT_EQ("SUCCESS", UserManager::removeUser(email, senha));
}