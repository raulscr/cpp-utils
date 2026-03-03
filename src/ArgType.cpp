#include "ArgType.h"

ArgType::ArgType(std::type_index type)
    : m_type(type)
{
}

std::type_index ArgType::type() const
{
    return m_type;
}

bool ArgType::isBool() const
{
    return m_type == typeid(bool);
}

bool ArgType::isString() const
{
    return m_type == typeid(std::string);
}
