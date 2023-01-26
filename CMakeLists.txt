cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(lab4 LANGUAGES CXX)
add_library(my_lib
    excursion.hpp
    excursion.cpp
    clutch_table.hpp
    clutch_table.cpp
    interface.hpp
    interface.cpp
    
)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    my_lib
)

enable_testing()


find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME}_ut
    test.cpp
)

target_link_libraries(${PROJECT_NAME}_ut
    my_lib
    GTest::GTest GTest::Main
)

#каждый тест выполняется отдельно

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_ut)

