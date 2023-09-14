#include "SqlAliasField.h"

AliasField::AliasField(const std::pair<std::string, std::string>& other) : AliasOperand(other.first, other.second)
{}

AliasField::AliasField(const std::string& name, const std::string& alias) : AliasOperand(name, alias)
{}

AliasField::operator std::string() const {
    return _name + (_alias.empty() ? " " : (" AS " + _alias + " "));
}
