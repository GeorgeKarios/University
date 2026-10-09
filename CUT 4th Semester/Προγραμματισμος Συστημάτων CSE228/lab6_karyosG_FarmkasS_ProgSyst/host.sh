#!/bin/sh
# Karyos Georgios 30738
# Stelios Farmkas 30833


for url in "$@"
do
    host $url >> results.txt
done
