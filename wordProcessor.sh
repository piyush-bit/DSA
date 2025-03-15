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
# The script reads individual words from the input file one at a time,
# removes duplicates, sorts them alphabetically, and writes the
# result to the output file.

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

# Create a temporary file to store processed words
temp_file=$(mktemp)

# Read and process one word at a time using grep
grep -o -E '\w+' "$1" | while read -r word; do
    # Convert to lowercase and store
    echo "$word" | tr '[:upper:]' '[:lower:]' >> "$temp_file"
done

# Sort the words and remove duplicates
sort "$temp_file" | uniq > "$2"

# Remove temporary file
rm "$temp_file"

# Check if processing was successful
if [ $? -eq 0 ]; then
    echo "Processing complete. Results saved to $2"
else
    echo "Error occurred during processing"
    exit 1
fi