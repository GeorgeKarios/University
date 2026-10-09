#!/bin/sh
# Karyos Georgios 30738
# Stelios Farmkas 30833

echo "Δώσε N:"
read N

i=1
while [ $i -le $N ]
do
    touch file$i
    i=$((i+1))
done
