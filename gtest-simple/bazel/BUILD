load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "square_plus_one_test",
    size = "small",
    srcs = ["tests/test_square_plus_one.cpp", "include/square_plus_one.hpp"],
    deps = ["@com_google_googletest//:gtest_main"],
    includes = ["include"],
    copts = ["--std=c++2a"],
)
