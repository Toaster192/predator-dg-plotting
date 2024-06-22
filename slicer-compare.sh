
bash ../smg_pta_run.sh $1.c plots/ >/dev/null 2>&1
clang -g -c -emit-llvm $1.c -o $1.bc

~/school/dg/tools/llvm-slicer -c __assert_fail $1.bc -pta smg --smg-dir=plots/
~/school/dg/tools/llvm-slicer -c __assert_fail $1.bc -pta fs 
