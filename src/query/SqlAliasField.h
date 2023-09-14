#ifndef CPPUTILS_QUERY_SQLALIASFIELD_H_
#define CPPUTILS_QUERY_SQLALIASFIELD_H_

#include "SqlAliasOperand.h"

#include <utility>

class AliasField : public AliasOperand {
public:
    explicit AliasField(const std::string& name, const std::string& alias = "");
    explicit AliasField(const std::pair<std::string, std::string>& other);
    virtual operator std::string() const override;
};

#endif // CPPUTILS_QUERY_SQLALIASFIELD_H_
