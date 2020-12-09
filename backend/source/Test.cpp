#include <gtest/gtest.h> // inclui biblioteca de teste gtest.
#include <JsonModule.h>
#include <DatabaseModule.h>
#include <UserManager.h>


GTEST_TEST(JsonModuleTest, registerUser) {
    Json::Value nome = "nome_teste";
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    Json::Value cpf = "12345678910";
    Json::Value phoneNum = "61988887777";
    GTEST_ASSERT_EQ("SUCESS", UserManager::registerUser(nome, email, senha, cpf, phoneNum));
}

/**
 * @brief Constroi objeto teste de JsonModuleTest.
 * 
 * Teste a função verifyLogin do modulo JsonModule.
 * 
 */
GTEST_TEST(JsonModuleTest, verifyLogin) {
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    GTEST_ASSERT_EQ("VALID_PASSWORD", UserManager::verifyLogin(email, senha));
    senha = "11111";
    GTEST_ASSERT_EQ("INVALID_PASSWORD", UserManager::verifyLogin(email, senha));
    email = "wrongteste@teste.com";
    GTEST_ASSERT_EQ("UNREGISTERED_USER", UserManager::verifyLogin(email, senha));
}

GTEST_TEST(JsonModuleTest, removeUser) {
    Json::Value email = "teste@teste.com";
    Json::Value senha = "12345";
    GTEST_ASSERT_EQ("SUCESS", UserManager::removeUser(email, senha));
}

/**
 * @brief Executa os teste
 * 
 * Prepara os testes do gtest e os executam.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}