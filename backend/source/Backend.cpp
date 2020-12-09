#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include "../headers/JsonModule.h"
#include "../headers/DatabaseModule.h"

int main() {
    std::string input;
    std::cin >> input;
    std::cout << JsonModule::BackendInterface(input);
}