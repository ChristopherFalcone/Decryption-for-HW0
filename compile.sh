#!/bin/bash
SRC_FILE="DecryptionHW0.cpp"
HLPR_FILE="DecryptionHelper.cpp"
OUTPUT_EXEC="Cipher"

#Compile
g++ "$SRC_FILE" "$HLPR_FILE" -o "$OUTPUT_EXEC" -std=c++20 -Wall

#Compilation check
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running program..."
    ./"$OUTPUT_EXEC"
else
    echo "Compilation failed."
fi