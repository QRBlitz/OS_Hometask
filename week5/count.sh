while ! ln ex2.txt ex2.lock 2>/dev/null
do
	sleep 0.1
done

count=$(tail -1 ex2.txt)

((count++))

echo $count >> ex2.txt

rm ex2.lock
