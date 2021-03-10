# this is unlikely to work on every machine or system
# it would scale incredibly badly with complexity and supported platforms
parent_dir=`dirname "$0"`

src=$parent_dir/src
include=$parent_dir/include
gen=$parent_dir/gen
build=$parent_dir/build_manual

set -x

mkdir $build
mkdir $build/src
mkdir $build/bin

python $gen/main.py hello $build/src/hello.cpp manual-bash
$CXX -c -I $include -o $build/hello.o $build/src/hello.cpp
$CXX -I $include -o $build/bin/hello_manual $src/main.cpp $build/hello.o

chmod 755 $build/bin/hello_manual

$build/bin/hello_manual
