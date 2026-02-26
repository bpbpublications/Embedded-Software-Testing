#!/bin/bash
# Compile and run unit tests for Chapter 7 code samples
# Companion to "Testing Embedded Software" by Gruenfelder & Mackay

set -e  # Exit on first error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "=========================================="
echo "Chapter 7 Unit Test Compilation Script"
echo "=========================================="
echo ""

# Clean up any previous builds
echo -e "${YELLOW}Cleaning up previous builds...${NC}"
rm -f test_runner out.txt flash_input.txt *.o

# List the source files
echo -e "${YELLOW}Source files to compile:${NC}"
echo "  - file_under_test.c  (file under test)"
echo "  - flash_routines.c   (flash routines stub)"
echo "  - test_file_sqrt.c   (test cases + main)"
echo ""
echo -e "${YELLOW}Header files:${NC}"
echo "  - flash_routines.h   (flash routines declarations)"
echo "  - framework.h        (test framework - MY_ASSERT macro)"
echo ""

# Compile
echo -e "${YELLOW}Compiling...${NC}"
gcc -w -o test_runner \
    file_under_test.c flash_routines.c test_file_sqrt.c \
    -lm

if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful!${NC}"
    echo ""
else
    echo -e "${RED}Compilation FAILED!${NC}"
    exit 1
fi

# Run the tests
echo "=========================================="
echo -e "${YELLOW}Running unit tests...${NC}"
echo "=========================================="
echo ""

./test_runner

echo ""
echo "=========================================="
echo -e "${GREEN}Test execution complete!${NC}"
echo "=========================================="

# Clean up generated files
echo ""
echo -e "${YELLOW}Cleaning up generated files...${NC}"
rm -f out.txt flash_input.txt
