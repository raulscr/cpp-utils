#ifndef CPPUTILS_QUERY_SQLSELECT_H_
#define CPPUTILS_QUERY_SQLSELECT_H_

#include <vector>
#include <string>

#include "SqlClause.h"
#include "SqlAliasField.h"
#include "SqlTable.h"

class Select : public Clause {
public:
    explicit Select(const std::vector<AliasField>& fields = {});
    virtual operator std::string() const;

    Select& From(const std::string& table);
    Select& From(const Table& table);

private:
    std::vector<AliasField> _fields;
    Table _table;
};

#endif // CPPUTILS_QUERY_SQLSELECT_H_
