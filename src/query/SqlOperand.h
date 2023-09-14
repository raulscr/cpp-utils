#ifndef CPPUTILS_QUERY_SQLOPERAND_H_
#define CPPUTILS_QUERY_SQLOPERAND_H_

#include <string>

class Operand {
public:
    virtual operator std::string() const = 0;
};

#endif // CPPUTILS_QUERY_SQLOPERAND_H_
