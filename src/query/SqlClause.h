#ifndef CPPUTILS_QUERY_SQLCLAUSE_H_
#define CPPUTILS_QUERY_SQLCLAUSE_H_

#include <string>

class Clause {
public:
    virtual operator std::string() const = 0;
};

#endif // CPPUTILS_QUERY_SQLCLAUSE_H_
