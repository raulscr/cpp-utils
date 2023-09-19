cmake_minimum_required(VERSION 3.8)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test-singleton test-singleton.cpp)

target_include_directories(test-singleton PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(test-singleton
    PRIVATE
    Boost::unit_test_framework
)

add_test(test-singleton test-singleton)