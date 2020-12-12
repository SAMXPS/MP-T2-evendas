#include "UserManagerTest.hpp"

TEST_F(UserManagerTest, registerUser) {
    UserManager::removeUser(test_email);
    GTEST_ASSERT_EQ(true, UserManager::registerUser(test_email, test_name, test_password));
    GTEST_ASSERT_EQ(false, UserManager::registerUser(test_email, test_name, test_password));
}

TEST_F(UserManagerTest, loadUser) {
    User* user = UserManager::loadUser(test_email);
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

TEST_F(UserManagerTest, removeUser) {
    GTEST_ASSERT_EQ(true, UserManager::removeUser(test_email));
}
