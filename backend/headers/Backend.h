#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
#include <istream>
#include <ostream>

/**
 * @brief classe que invoca o metodo BackendInterface que processa os dados Json
 * 
 */
class Backend {
    public:
        Backend() { }
        /**
         * @brief Roda o metodo que processa dados Json
         * 
         * @param input 
         * @param output 
         */
        void run(std::istream&input, std::ostream&output);
};

#endif//BACKEND_H_INCLUDED