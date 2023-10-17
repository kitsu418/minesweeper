#!/bin/bash

bdf_file="ib16x16u.bdf"

echo -e "const unsigned short characters[][14] = {" > output_with_header.txt

awk '/STARTCHAR/ { char_name = $2 } /STARTCHAR/,/ENDCHAR/ { if (/BITMAP/) { getline; printf "    // %s\n    {", char_name; while (!/ENDCHAR/) { printf "0x%s, ", $1; getline } print "},"} }' "$bdf_file" >> output_with_header.txt

echo "};" >> output_with_header.txt
