name=/share/plots
if [[ -e $name || -L $name ]] ; then
    i=0
    while [[ -e $name-$i || -L $name-$i ]] ; do
        let i++
    done
    name=$name-$i
fi

mkdir $name

cp ./plots/_ps.dot $name/
cp ./plots/*.dot $name/

cd $name/

find ./ -type f -name "*.dot" | xargs dot -Tpdf -O
