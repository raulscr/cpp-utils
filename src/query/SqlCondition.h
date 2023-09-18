#ifndef CPPUTILS_QUERY_SQLCONDITION_H_
#define CPPUTILS_QUERY_SQLCONDITION_H_

#include <string>

#include "SqlClause.h"

class Condition : public Clause {
public:
    enum Operator {
        IS,
        IS_NOT,
        LIKE,
        EQUAL,
        NOT_EQUAL,
        LESS_THAN,
        LESS_EQUAL,
        GREATER_THAN,
        GREATER_EQUAL,
        // TODO: investigate possible operators and implement them
    };

    explicit Condition(const Condition& other);
    Condition(const std::string& value = "");
    virtual operator std::string() const;

    virtual bool IsValid() const;

    Condition& Equal(const std::string& other);
    Condition& NotEqual(const std::string& other);

    Condition& IsNull();
    Condition& IsNotNull();

protected:
    Operator _operator;
    // TODO: use SqlValue (not implemented yet)
    std::string _first_value;
    std::string _second_value;
};

#endif // CPPUTILS_QUERY_SQLCONDITION_H_
