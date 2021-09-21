counter=1;

echo 1 > ex2.txt

while [ $counter -lt 20 ] 
do
	bash count.sh
	bash count.sh &
	
	((counter++))
done
