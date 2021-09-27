project('gtest-simple', 'cpp', default_options : ['cpp_std=c++2a'])

include = include_directories('include')

gtest = subproject('gtest')
gtest_deps = [
    gtest.get_variable('gtest_dep'),
    gtest.get_variable('gtest_main_dep')
]

main = executable(
    'main',
    'src' / 'main.cpp',
    include_directories : include
)

square_plus_one_test = executable(
    'square-plus-one-test',
    'tests' / 'test_square_plus_one.cpp',
    dependencies : [gtest_deps],
    include_directories : include
)

test('test-square-plus-one', square_plus_one_test)
