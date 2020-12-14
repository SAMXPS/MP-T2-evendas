#include "UserManagerTest.hpp"

TEST_F(UserManagerTest, registerUser) {
    UserManager::removeUser(test_email);
    GTEST_ASSERT_EQ(true, UserManager::registerUser(test_email, test_name, test_password));
    GTEST_ASSERT_EQ(false, UserManager::registerUser(test_email, test_name, test_password));
}

TEST_F(UserManagerTest, loadUser) {
    User* user = UserManager::loadUser(wrong_test_email);
    GTEST_ASSERT_EQ(nullptr, user);
    user = UserManager::loadUser(test_email);
    GTEST_ASSERT_NE(nullptr, user);
    GTEST_ASSERT_EQ(test_name, user->getName());
    GTEST_ASSERT_EQ(test_email, user->getEmail());
    GTEST_ASSERT_EQ(test_password, user->getPassword());
    delete user;
}

TEST_F(UserManagerTest, verifyLogin) {
    GTEST_ASSERT_NE(nullptr, UserManager::verifyLogin(test_email, test_password));
    GTEST_ASSERT_EQ(nullptr, UserManager::verifyLogin(test_email, wrong_password));
}

TEST_F(UserManagerTest, createUserData) {
    User* user = UserManager::loadUser(test_email);
    GTEST_ASSERT_NE(nullptr, user);
    UserData data(user->getId(), "Rua Teste, Bairro Teste0", "123.123.123-12", "+55 61 9 9999-9999");
    GTEST_ASSERT_EQ(true, UserManager::saveUserData(data));

    delete user;
}

TEST_F(UserManagerTest, loadUserData) {
    User* user = UserManager::loadUser(test_email);
    GTEST_ASSERT_NE(nullptr, user);

    UserData test_data(user->getId(), "Rua Teste, Bairro Teste0", "123.123.123-12", "+55 61 9 9999-9999");
    UserData* db_data = UserManager::loadUserData(user->getId());
    GTEST_ASSERT_NE(nullptr, db_data);
    GTEST_ASSERT_EQ(test_data.getId(), db_data->getId());
    GTEST_ASSERT_EQ(test_data.getAddress(), db_data->getAddress());
    GTEST_ASSERT_EQ(test_data.getDocument(), db_data->getDocument());
    GTEST_ASSERT_EQ(test_data.getPhoneNumber(), db_data->getPhoneNumber());

    delete db_data;
    delete user;
}

TEST_F(UserManagerTest, removeUser) {
    User* user = UserManager::loadUser(test_email);
    GTEST_ASSERT_EQ(true, UserManager::removeUser(test_email));
    if (user) {
        // Dados do usuário também devem ter sido removidos automaticamente
        GTEST_ASSERT_EQ(nullptr, UserManager::loadUserData(user->getId()));
        delete user;
    }
}
