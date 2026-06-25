#!/bin/bash

# Check if a filename was provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <JavaFile.java>"
    exit 1
fi

JAVA_FILE="$1"

# Check if the file exists
if [ ! -f "$JAVA_FILE" ]; then
    echo "Error: File '$JAVA_FILE' not found"
    exit 1
fi

# Check if the file has .java extension
if [[ ! "$JAVA_FILE" =~ \.java$ ]]; then
    echo "Error: File must have .java extension"
    exit 1
fi

echo "====== Compilation in progress ======"
mkdir -p output

# Copy the file to output directory
cp "$JAVA_FILE" output/

# Get the class name (filename without .java)
CLASS_NAME="${JAVA_FILE%.java}"
CLASS_NAME=$(basename "$CLASS_NAME")

# Compile the Java file
javac output/"$JAVA_FILE"
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    rm -rf output
    exit 1
fi

echo "====== Execution in progress ======"
# Run the Java program
java -cp output "$CLASS_NAME"
EXIT_CODE=$?

echo "====== Cleaning up directory ======"
rm -rf output

exit $EXIT_CODE