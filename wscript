APPNAME = "hello-waf"
VERSION = "1.0"

top = "."
out = "build-waf"
includes = [top + "/include"]

hellolib_src = "src/hellolib.cpp"

def options(ctx):
    ctx.load("compiler_cxx")


def configure(ctx):
    ctx.load("compiler_cxx")
    ctx.env.append_value("CXXFLAGS", ["--std=c++17"])


def build(ctx):
    ctx(rule="python ${SRC} hello ${TGT} waf", source="gen/main.py", target=hellolib_src)
    ctx.shlib(source=hellolib_src, target="hellolib", includes=includes)
    ctx.program("hello-waf", source="src/main.cpp", target="hello-waf", use="hellolib", includes=includes)
    ctx(rule="./${SRC}", source="hello-waf", always=True)
