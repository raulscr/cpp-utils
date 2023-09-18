#include "SqlSelect.h"

Select::operator std::string() const {
    std::string query = "SELECT";

    for (int i = 0; i < _fields.size(); i++) {
        query += _fields[i];
        if (i < _fields.size() - 1) {
            query += ",";
        }
    }

    // TODO make expection case no table
    query += _table;
    // or maybe not, user problems...

    if (_conditions.IsValid()) {
        query += " WHERE";
        query += _conditions;
    }

    query += ";";
    return query;
}

Select::Select(const std::vector<AliasField>& fields) : _fields{fields}{
}

Select& Select::From(const std::string& table){
    _table = Table(table);
    return *this;
}

Select& Select::From(const Table& table){
    _table = table;
    return *this;
}

Select &Select::Where(const Conditions &conditions){
    _conditions = conditions;
    return *this;
}
