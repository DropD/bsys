project('bsys-meson', 'cpp')

prog_python = import('python').find_installation('python3')
prog_bash = find_program('bash')
inc_dir = include_directories('include')

hellolib_src = custom_target(
    'gen-hello',
    input : 'gen' / 'main.py',
    output : 'hellolib.cpp',
    command : [prog_python, '@INPUT@', 'hello', '@OUTPUT@', 'meson'],
)

hellolib = library('hellolib', hellolib_src, include_directories : inc_dir)

hello = executable('hello-meson', 'src' / 'main.cpp', link_with: hellolib, include_directories : inc_dir)

test('run-hello', hello)
test('test-hello', prog_bash, args : ['/Users/ricoh/Code/bsys/test_hello.sh', hello.full_path(), 'Hello meson'])
#test('test-hello', prog_tester, args : ['hello-meson'])
