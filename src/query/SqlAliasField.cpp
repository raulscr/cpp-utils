#include "SqlAliasField.h"

AliasField::AliasField(const std::string& name, const std::string& alias) : AliasOperand(name, alias)
{ }

AliasField::operator std::string() const {
    return _name + (_alias.empty() ? " " : (" AS " + _alias + " "));
}
