mkdir -p plots
cd plots
find ./ -name "*.pdf" -delete
find ./ -name "*.dot" -delete
find ./ -name "*.json" -delete
find ./ -name "*.bc" -delete
find ./ -name "*.i" -delete

cp ../$1 ./$1

CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ /home/toaster/school/predator-llvm/sl/slllvm $1

#CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ perf record -g /home/toaster/school/dg/tools/dgtool llvm-pta-dump --pta smg --smg-dir ./ $1

CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ /home/toaster/school/dg/tools/dgtool llvm-pta-dump --pta smg --smg-dir ./ $1

find ./ -name "$1" -delete
#find ./ -type f -name "*.dot" | xargs dot -Tpdf -O
