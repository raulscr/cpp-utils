cmake_minimum_required(VERSION 3.8)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test-query-builder test-query-builder.cpp)

target_link_libraries(test-query-builder
    PRIVATE
    Boost::unit_test_framework
)

add_test(test-query-builder test-query-builder)