#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE query_builder

#include <string>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE ( SimpleSelectQueryTest ) {
	const std::string expected_query = "SELECT test_field FROM test_table;";
	BOOST_CHECK_EQUAL ( expected_query, "" );
}
