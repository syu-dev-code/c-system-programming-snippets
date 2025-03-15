#!/bin/bash
src_file=${1}

if [ -z "$src_file" ]; then
    echo "Usage: $0 <source_file>"
    exit 1
fi

echo -e "\033[32m[Building ${src_file%.c}]\033[0m"
executable=$(./build.sh ${src_file})
trap 'echo -e "\033[32m[Finished running ${src_file%.c}]\033[0m"; rm -f "${executable}"' EXIT
echo -e "\033[32m[Finished building ${src_file%.c}]\033[0m"
echo -e "\033[32m[Running ${src_file%.c}]\033[0m"
"${executable}"