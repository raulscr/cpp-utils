#include "SqlConditions.h"

Conditions::Conditions(const Condition& condition) :
    Condition{condition},
    _conditions{}{
}

Conditions::Conditions() :
    Conditions{Condition{}}{
}

Conditions::Conditions(const Conditions &conditions) :
    Condition{*this},
    _conditions{conditions}{
}

bool Conditions::Validate() const {
    return Condition::Validate();
}
