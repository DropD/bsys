set -x

output=`$1`

if [ "$output" = "$2" ]; then
    echo "PASSED"
else
    echo "FAILED"
    exit -1
fi
