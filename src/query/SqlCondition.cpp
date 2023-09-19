#include "SqlCondition.h"

Condition::Condition(const Condition &other) :
    _operator{other._operator},
    _first_value{other._first_value},
    _second_value{other._second_value}{
}

Condition::Condition(const std::string &value) :
    _operator{INVALID_OPERATOR},
    _first_value{value}{
}

Condition::operator std::string() const {
    // TODO: implement how to diff operators
    return " " + _first_value;
}

bool Condition::IsValid() const {
    return !_first_value.empty();
}

Condition& Condition::Equal(const std::string& other){
    _operator     = Operator::EQUAL;
    _second_value = other;
    return *this;
}

Condition& Condition::NotEqual(const std::string& other){
    _operator     = Operator::NOT_EQUAL;
    _second_value = other;
    return *this;
}

Condition& Condition::IsNull(){
    _operator     = Operator::IS;
    _second_value = "NULL";
    return *this;
}

Condition& Condition::IsNotNull(){
    _operator     = Operator::IS_NOT;
    _second_value = "NULL";
    return *this;
}
