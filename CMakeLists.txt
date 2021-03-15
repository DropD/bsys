cmake_minimum_required(VERSION 3.10)

project(bsys-cmake)

enable_testing()

include(FindPythonInterp)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(GENERATOR ${PROJECT_SOURCE_DIR}/gen/main.py)
set(HELLO ${PROJECT_BINARY_DIR}/hello.cpp)

add_custom_command(
    OUTPUT ${HELLO}
    COMMAND ${PYTHON_EXECUTABLE} ${GENERATOR} hello ${HELLO} cmake
    DEPENDS ${GENERATOR}
    COMMENT "Generating hello.cpp"
)

add_library(hellolib ${HELLO})

add_executable(hello_cmake src/main.cpp)

target_link_libraries(hello_cmake hellolib)

add_test(NAME say-hello COMMAND hello_cmake)
set_tests_properties(say-hello PROPERTIES PASS_REGULAR_EXPRESSION "Hello cmake")
