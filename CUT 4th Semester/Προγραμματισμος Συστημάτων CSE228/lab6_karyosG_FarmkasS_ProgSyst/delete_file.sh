#!/bin/sh
# Karyos Georgios 30738
# Stelios Farmkas 30833


if [ $# -eq 0 ]
then
    echo "Δεν δόθηκε όρισμα"
    exit 1
fi

if [ ! -f "$1" ]
then
    echo "Το αρχείο δεν υπάρχει"
    exit 1
fi

echo "Θέλεις να διαγράψεις το $1? (y/n)"
read ans

if [ "$ans" = "y" ]
then
    rm "$1"
    echo "Διαγράφηκε"
else
    echo "Ακύρωση"
fi
