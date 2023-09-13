#ifndef CPPUTILS_QUERY_SQLSELECT_H_
#define CPPUTILS_QUERY_SQLSELECT_H_

#include "SqlClause.h"

class Select : Clause {
public:
    operator std::string() const;
};

#endif // CPPUTILS_QUERY_SQLSELECT_H_
