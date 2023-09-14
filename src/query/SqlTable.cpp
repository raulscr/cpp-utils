#include "SqlTable.h"

Table::Table(const std::string& name, const std::string& alias) : AliasOperand(name, alias)
{}

Table::operator std::string() const {
    return _name + (_alias.empty() ? " " : (_alias + " "));
}
