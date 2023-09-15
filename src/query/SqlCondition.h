#ifndef CPPUTILS_QUERY_SQLCONDITION_H_
#define CPPUTILS_QUERY_SQLCONDITION_H_

#include <string>

#include "SqlClause.h"

class Condition : public Clause {
public:
    explicit Condition(const Condition& other);
    Condition(const std::string& value = "");
    virtual operator std::string() const;

    virtual bool Validate() const;

    Condition& IsEqual(const std::string& other);
    Condition& IsNull();
    // TODO: investigate possible operators and implement them

protected:
    // TODO: use SqlValue (not implemented yet)
    std::string _first_value;
    std::string _second_value;
};

#endif // CPPUTILS_QUERY_SQLCONDITION_H_
