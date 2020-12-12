#include "../headers/Backend.h"
#include "../headers/JsonModule.h"
#include <iostream>

int main() {
    Backend* backend = new Backend();
    backend->run(std::cin, std::cout);
}

void Backend::run(std::istream&input, std::ostream&output) {
    output << JsonModule::BackendInterface(input);
}