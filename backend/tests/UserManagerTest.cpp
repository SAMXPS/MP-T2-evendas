#include "UserManagerTest.hpp"

TEST_F(UserManagerTest, verifyLogin) {
    std::string email = "teste@teste.com";
    std::string senha = "12345";
    GTEST_ASSERT_EQ("VALID_PASSWORD", UserManager::verifyLogin(email, senha));
    senha = "11111";
    GTEST_ASSERT_EQ("INVALID_PASSWORD", UserManager::verifyLogin(email, senha));
    email = "wrongteste@teste.com";
    GTEST_ASSERT_EQ("UNREGISTERED_USER", UserManager::verifyLogin(email, senha));
}

TEST_F(UserManagerTest, loadUser) {
    std::string email = "teste@teste.com";
    if (UserManager::loadUser(email) != NULL) {
        GTEST_ASSERT_EQ("teste@teste.com", UserManager::loadUser(email)->getEmail());
    }
}

TEST_F(UserManagerTest, registerUser) {
    std::string nome = "nome_teste";
    std::string email = "teste@teste.com";
    std::string senha = "12345";
    GTEST_ASSERT_EQ("SUCCESS", UserManager::registerUser(email, nome, senha));
}



TEST_F(UserManagerTest, removeUser) {
    std::string email = "teste@teste.com";
    std::string senha = "12345";
    GTEST_ASSERT_EQ("SUCCESS", UserManager::removeUser(email));
}
