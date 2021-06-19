for((i=1;;++i)); do
	echo $i
	./gen $i>int
	diff -w <(./B<int) <(py wrong.py<int) || break
done

