#include "SqlAliasOperand.h"

AliasOperand::AliasOperand(const std::string& name, const std::string& alias) : _name{name}, _alias{alias}
{ }

AliasOperand::operator std::string() const {
    return " AliasOperand ";
}
