#ifndef CPPUTILS_QUERY_SQLTABLE_H_
#define CPPUTILS_QUERY_SQLTABLE_H_

#include "SqlAliasOperand.h"

class Table : public AliasOperand {
public:
    explicit Table(const std::string& name, const std::string& alias = "");
    virtual operator std::string() const override;
};

#endif // CPPUTILS_QUERY_SQLTABLE_H_
