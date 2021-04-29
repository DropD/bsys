load("@gen_deps//:requirements.bzl", "requirement")
load(":gen.bzl", "gen_hello")
load(":gen.bzl", "test_hello")

py_binary(
    name = "cppgen",
    srcs = ["//:gen/main.py"],
    main = "main.py",
    deps = [requirement("click")],
)

gen_hello(
    name = "hellolib.cpp",
    generator = "//:cppgen",
)

cc_library(
    name = "hellolib",
    srcs = [":hellolib.cpp"],
    hdrs = ["include/bsys.hpp"],
    copts = ["-Iinclude"]
)

cc_binary(
    name = "hello-bazel",
    srcs = ["src/main.cpp"],
    deps = [":hellolib"],
    copts = ["-Iinclude"]
)

sh_test(
    name = "test-hello",
    size = "small",
    srcs = ["test_hello.sh"],
    args = ["hello-bazel", "'Hello bazel'"],
    data = [":hello-bazel"],
)
