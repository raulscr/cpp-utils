#ifndef CPPUTILS_QUERY_SQLCONDITIONS_H_
#define CPPUTILS_QUERY_SQLCONDITIONS_H_

#include <vector>
#include <string>

#include "SqlCondition.h"

class Conditions : public Condition {
public:
    Conditions();
    Conditions(const Condition& condition);
    explicit Conditions(const Conditions& conditions);

    // virtual operator std::string() const override;

    bool Validate() const override;

private:
    std::vector<Condition> _conditions;
};

#endif // CPPUTILS_QUERY_SQLCONDITIONS_H_
