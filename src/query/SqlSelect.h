#ifndef CPPUTILS_QUERY_SQLSELECT_H_
#define CPPUTILS_QUERY_SQLSELECT_H_

#include "SqlClause.h"

class Select : public Clause {
public:
    virtual operator std::string() const;
};

#endif // CPPUTILS_QUERY_SQLSELECT_H_
