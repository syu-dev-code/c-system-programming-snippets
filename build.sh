#!/bin/bash
src_file=${1}

if [ -z "$src_file" ]; then
    echo "Usage: $0 <source_file>"
    exit 1
fi

executable=$(mktemp -p /tmp)
gcc -Wall -W -O2 -lrt -g -o "${executable}" "${src_file}"
echo "${executable}"
