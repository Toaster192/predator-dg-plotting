rm -rf ./plots
mkdir plots
cd plots

sed '/__VERIFIER_plot/d' ../$1 | sed '/verifier-builtins/d' > clear-$1

~/school/predator-llvm/sl/slllvm clear-$1

~/school/dg/tools/dgtool llvm-pta-dump --pta smg --smg-dir ./ clear-$1

find ./ -type f -name "*.dot" | xargs dot -Tpdf -O
