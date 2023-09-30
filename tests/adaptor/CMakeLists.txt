cmake_minimum_required(VERSION 3.8)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test-adaptor test-adaptor.cpp)

target_include_directories(test-adaptor PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(test-adaptor
    PRIVATE
    Boost::unit_test_framework
)

add_test(test-adaptor test-adaptor)