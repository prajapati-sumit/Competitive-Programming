
input = "inp";
output = "out";
for((i=1;;++i)); do
    echo $i
    tmpinp = $input+$i
    tmpout = $output+$i;
    ./gen >$tmpinp
    <(./correct<$tmpinp)>$tmpout
done

