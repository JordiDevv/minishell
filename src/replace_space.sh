#!/bin/bash

# Tab width: how many spaces = 1 tab?
TAB_WIDTH=4

# Find all .c and .h files
find . -type f \( -name "*.c" -o -name "*.h" \) | while read -r file; do
    echo "Processing: $file"

    # Use sed to replace leading spaces with tabs
    # Create a temporary file and replace original after edit
    sed -E "s/^([ ]{$TAB_WIDTH})+/\t/g" "$file" > "$file.tmp" && mv "$file.tmp" "$file"
done

echo "Indentation conversion completed!"
