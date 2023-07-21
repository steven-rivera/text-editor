#!/bin/bash

# Create the "obj" folder if it doesn't exist
mkdir -p obj  

# Compile .cpp files
for file in ./app/*.cpp; do
    filename=$(basename "$file")
    g++ -c "$file" -o "obj/${filename%.cpp}.o"
done

# Link object files
g++ -o text-editor.out ./obj/*.o -lncurses