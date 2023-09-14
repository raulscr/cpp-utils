#ifndef CPPUTILS_QUERY_SQLALIASFIELD_H_
#define CPPUTILS_QUERY_SQLALIASFIELD_H_

#include "SqlAliasOperand.h"

class AliasField : public AliasOperand {
public:
    explicit AliasField(const std::string& name, const std::string& alias = "");
    virtual operator std::string() const override;
};

#endif // CPPUTILS_QUERY_SQLALIASFIELD_H_