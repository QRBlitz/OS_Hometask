counter=1;

if [ ! -f ex2.txt ]; then
	echo 1 > ex2.txt	
fi

while [ $counter -lt 100 ] 
do
	bash count.sh
	bash count.sh &
	
	((counter++))
done
