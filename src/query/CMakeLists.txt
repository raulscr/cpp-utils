
set(SOURCES
    SqlTable.cpp
    SqlSelect.cpp
    SqlAliasField.cpp
    SqlAliasOperand.cpp
)

add_library(query ${SOURCES})

target_include_directories(query PUBLIC ${PROJECT_SOURCE_DIR})