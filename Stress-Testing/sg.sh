for((i=1;;++i)); do
	echo $i
	./gen $i>inp.txt
	diff -w <(./correct<inp.txt) <(./wrong<inp.txt) || break
done

