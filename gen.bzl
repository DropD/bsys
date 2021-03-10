def _gen_hello_impl(ctx):
    out = ctx.actions.declare_file(ctx.label.name)
    ctx.actions.run(outputs=[out], arguments=["hello", out.path, "bazel"], executable=ctx.executable.generator)
    return [DefaultInfo(files = depset([out]))]


gen_hello = rule(
    implementation = _gen_hello_impl,
    attrs = {
        "generator": attr.label(
            executable = True,
            cfg = "exec",
        ),
    }
)


def _test_hello_impl(ctx):
    out = ctx.actions.declare_file(ctx.label.name)
    ctx.actions.run(executable=ctx.executable.binary, outputs=[out])


test_hello = rule(
    implementation = _test_hello_impl,
    attrs = {
        "binary": attr.label(
            executable = True,
            cfg = "exec",
        )
    }
)
