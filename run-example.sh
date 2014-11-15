clang -O3 -emit-llvm example.c -c -o example.bc
../../../Debug+Asserts/bin/opt -load ../../../Debug+Asserts/lib/TypeSection.so -type-section < example.bc > /dev/null

