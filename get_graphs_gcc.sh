
rm -rf ./plots
mkdir plots
cd plots

sed '/__VERIFIER_plot/d' ../$1 | sed '/verifier-builtins/d' > clear-$1

~/school/dg/tools/dgtool pta-show clear-$1

~/school/predator-gcc/sl/slgcc ../$1
~/school/predator/sl/slllvm ../$1
