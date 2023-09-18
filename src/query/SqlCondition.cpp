#include "SqlCondition.h"

Condition::Condition(const Condition &other) :
    _first_value{other._first_value},
    _second_value{other._second_value}{
}

Condition::Condition(const std::string &value) :
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
    // TODO
    return *this;
}

Condition& Condition::IsNull(){
    // TODO
    return *this;
}
