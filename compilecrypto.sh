#!/bin/bash
SRC_FILE="CryptoHW0.cpp"
OUTPUT_EXEC="Cipher"

#Compile
g++ "$SRC_FILE" -o "$OUTPUT_EXEC" -std=c++20 -Wall

#Compilation check
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running program..."
    ./"$OUTPUT_EXEC"
else
    echo "Compilation failed."
fi