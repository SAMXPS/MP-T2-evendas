#include <iostream>
#include <sstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "../headers/JsonModule.h"
#include "../headers/DatabaseModule.h"

int main() {
    std::cout << JsonModule::BackendInterface(std::cin);
}