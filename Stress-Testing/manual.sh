for((i=1;i<50;++i)); do
    echo $i
    ./gen $i>inp.txt
    ./wrong<inp.txt > inp.txt)) 
    value=$(<inp.txt)
    echo "$value"
done

