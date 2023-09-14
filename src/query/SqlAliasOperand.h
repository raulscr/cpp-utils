#ifndef CPPUTILS_QUERY_SQLALIASOPERAND_H_
#define CPPUTILS_QUERY_SQLALIASOPERAND_H_

#include "SqlOperand.h"

class AliasOperand : public Operand {
public:
    explicit AliasOperand(const std::string& name, const std::string& alias = "");
    virtual operator std::string() const;
protected:
    std::string _name;
    std::string _alias;
};

#endif // CPPUTILS_QUERY_SQLALIASOPERAND_H_
