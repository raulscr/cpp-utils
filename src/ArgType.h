#pragma once

#include <string>
#include <typeindex>

class ArgType
{
public:
    ArgType(std::type_index type);

    std::type_index type() const;

    bool isBool() const;
    bool isString() const;

private:
    std::type_index m_type;
};
