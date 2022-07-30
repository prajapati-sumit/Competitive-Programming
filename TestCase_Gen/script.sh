
input="input"
output="output"
echo "Compiling ${1}"
g++ -std=c++17 "${1}.cpp" -o ${1}
echo "Compiling ${2}"
g++ -std=c++17 "${2}.cpp" -o ${2}
for((i=0;i<${3};++i)); do
    tmpinp="input/$input$((i/10))$((i%10)).txt"
    tmpout="output/$output$((i/10))$((i%10)).txt"
    touch $tmpout
    echo "Generating Test $i"
    ./$1 >$tmpinp
    ./$2<$tmpinp>$tmpout
done

