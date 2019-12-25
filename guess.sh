#Store the number of try
count=0
#Store a random number 
a=$((( RANDOM % $1 ) + 1 ))
#Store the guess
guess=0
echo "Make a Guess"
#Take input until the right guess
while [ "$guess" != "$a" ]
do
#Take input
read var1
#As number
guess=$(($var1+0))
let "count=count+1"
	#Check the whetever lower or higher
	if [[ $guess -gt $a ]];then
		echo "LOWER!"
	elif [[ $guess -lt $a ]];then
		echo "HIGHER!"
	else
		echo "\nCORRECT!!!"
	fi
#Output for the user
echo Your guess: $guess
echo Number of try: $count
done
echo "You guessed my number $count tries!"
