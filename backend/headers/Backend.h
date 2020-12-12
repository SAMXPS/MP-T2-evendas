#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
#include <istream>
#include <ostream>

class Backend {
    public:
        Backend() { }
        void run(std::istream input, std::ostream output);
};

#endif//BACKEND_H_INCLUDED