#!/bin/bash

# Filename to modify
filename="ar9003_eeprom.c"

# Create a temporary backup of the original file
cp "$filename" "$filename.bak"

# Use sed to add (u8) before each instance of FREQ2BIN(
sed -i 's/FREQ2FBIN(/(u8)FREQ2FBIN(/g' "$filename"

# Inform the user about the changes
echo "Casts (u8) have been added to FREQ2FBIN instances in $filename."
echo "The original file has been backed up as $filename.bak."

