#include <gtest/gtest.h> // inclui biblioteca de teste gtest.
#include <JsonModule.h>


/**
 * @brief Constroi novo objeto de teste do gtest.
 * 
 * Teste a função verifyLogin do modulo JsonModule.
 * 
 */
GTEST_TEST(JsonModuleTest, verifyLogin) {
    Json::Value usuario = "teste@teste.com";
    Json::Value senha = "teste";

    GTEST_ASSERT_EQ("VALID_PASSWORD", JsonModule::verifyLogin(usuario, senha));
    usuario = "wrongteste@teste.com";
    senha = "wrongpassword";
    GTEST_ASSERT_EQ("INVALID_PASSWORD", JsonModule::verifyLogin(usuario, senha));

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