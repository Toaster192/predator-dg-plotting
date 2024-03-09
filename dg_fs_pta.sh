cd plots

sed '/__VERIFIER_plot/d' ../$1 | sed '/verifier-builtins/d' > clear-$1

~/school/dg/tools/dgtool llvm-pta-dump --pta fs clear-$1
