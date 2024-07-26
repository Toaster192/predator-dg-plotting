mkdir -p plots
cd plots
find ./ -name "*.pdf" -delete
find ./ -name "*.dot" -delete
find ./ -name "*.json" -delete
find ./ -name "*.bc" -delete
#find ./ -name "clear-*.c" -delete
#find ./ -name "clear-*.i" -delete
#find ./ -name "*.c" -delete
find ./ -name "*.i" -delete

cp ../$1 ./$1
#sed '/__VERIFIER_plot/d' ../$1 | sed '/verifier-builtins/d' > clear-$1

#~/school/predator-llvm/sl/slllvm clear-$1

#~/school/dg/tools/dgtool llvm-pta-dump --pta smg --smg-dir ./ clear-$1

CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ ~/school/predator-llvm/sl/slllvm $1

#CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ ~/school/dg/tools/dgtool llvm-pta-dump --pta smg --smg-dir ./ $1

CPATH=/home/toaster/school/predator-llvm/include/predator-builtins/ CPLUS_INCLUDE_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ LIBRARY_PATH=/home/toaster/school/predator-llvm/include/predator-builtins/ /home/toaster/school/dg/tools/dgtool llvm-pta-compare --strict --smg --fs --pta smg --smg-dir ./ $1

find ./ -name "$1" -delete
find ./ -type f -name "*.dot" | xargs dot -Tpdf -O
