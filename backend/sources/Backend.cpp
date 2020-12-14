// Copyright 2020 Samuel James, Leonam Gomes
#include <iostream>
#include "../headers/Backend.h"
#include "../headers/JsonModule.h"

int main() {
    Backend* backend = new Backend();
    backend->run(std::cin, std::cout);
}

void Backend::run(std::istream&input, std::ostream&output) {
    output << JsonModule::BackendInterface(input);
}
