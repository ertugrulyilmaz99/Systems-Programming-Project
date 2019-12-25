#Store the weight as a number
weight=$(($1+0))
weight=$( echo "scale=2;($weight)*10000" | bc )

#Store the height as a number
height=$(($2+0))
height=$( echo "scale=2;($height*$height)" | bc )

#Calculation of the body mass index
bmi=$( echo "scale=2;$weight/$(($height))" | bc )
#Rounding
bmi=$( echo "scale=0;$weight/$(($height))" | bc )
#Print the BMI
echo BMI: $bmi

#Check the conditions for the right classification of bmi

if [[ $bmi -lt 19 ]];then
	echo "UNDERWEIGHT"
	echo Weight: $1kg  Height: $2cm "\n"BMI: $bmi "\n"RESULT: Underweight | cat> ./Desktop/Project/bmi.txt
elif [[ $bmi -lt 25 ]];then
	echo "HEALTY"
	echo Weight: $1kg  Height: $2cm "\n"BMI: $bmi "\n"RESULT: Healty | cat> ./Desktop/Project/bmi.txt
elif [[ $bmi -lt 30 ]];then 
	echo "OVERWEIGHT"
	echo Weight: $1kg  Height: $2cm "\n"BMI: $bmi "\n"RESULT: Overweight | cat> ./Desktop/Project/bmi.txt
elif [[ $bmi -lt 40 ]];then
	echo "OBESE"
	echo Weight: $1kg  Height: $2cm "\n"BMI: $bmi "\n"RESULT: Obese | cat> ./Desktop/Project/bmi.txt
elif [[ $bmi -lt 51 ]];then
	echo "EXTEREME OBESE"
	echo Weight: $1kg  Height: $2cm "\n"BMI: $bmi "\n"RESULT: Extreme Obese | cat> ./Desktop/Project/bmi.txt
else
	echo "***illegal values**"
fi

