#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include "../headers/JsonModule.h"

int main() {
    std::string input;
    std::cin >> input;
    std::cout << JsonModule::Get(input);
}