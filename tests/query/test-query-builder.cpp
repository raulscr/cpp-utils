#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE query_builder

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

#include <query/SqlSelect.h>

BOOST_AUTO_TEST_CASE(SimpleSelectQueryTest){
    const std::string expected_query = "SELECT * FROM test_table;";

    const std::string actual_query =
      Select({ { "*" } })
      .From("test_table");

    BOOST_CHECK_EQUAL(expected_query, actual_query);
}

BOOST_AUTO_TEST_CASE(SelectWithFieldsQueryTest){
    const std::string expected_query =
      "SELECT test_table.test_field, test_table.test_field2 AS field2 FROM test_table;";

    const std::string actual_query =
      Select({
        { "test_table.test_field" },
        { "test_table.test_field2", "field2" }
    })
      .From("test_table");

    BOOST_CHECK_EQUAL(expected_query, actual_query);
}
