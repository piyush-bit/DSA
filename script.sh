#!/bin/bash

# Assignment Name: Word Processing Script
# Date: October 24, 2024
# Course: COP4342
# Term: Fall 2024
# Name: [Your Name]
#
# Description: This script takes two parameters:
# 1. An input text file containing multiple words per line
# 2. An output file name
# The script reads all words from the input file, removes duplicates,
# sorts them alphabetically, and writes the result to the output file.

# Check if correct number of parameters are provided
if [ $# -ne 2 ]; then
    echo "Error: Script requires exactly two parameters"
    echo "Usage: $0 input_file output_file"
    exit 1
fi

# Check if input file exists
if [ ! -f "$1" ]; then
    echo "Error: Input file '$1' does not exist"
    exit 1
fi

# Process the file:
# 1. Read the input file using cat
# 2. Convert to lowercase and replace punctuation with spaces using tr
# 3. Convert all whitespace (including newlines) to single spaces
# 4. Convert the single space-separated string into one word per line
# 5. Sort the words
# 6. Remove duplicates
# 7. Save to output file
cat "$1" | \
    tr '[:upper:]' '[:lower:]' | \
    tr -c '[:alnum:]' ' ' | \
    tr -s '[:space:]' '\n' | \
    sort | \
    uniq > "$2"

# Check if processing was successful
if [ $? -eq 0 ]; then
    echo "Processing complete. Results saved to $2"
else
    echo "Error occurred during processing"
    exit 1
fi