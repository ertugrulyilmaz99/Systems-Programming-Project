#include <stdio.h>

void primes(int in);
	
void primes(int in){
//The prime numbers until 100
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29 ,31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//How man prime numbers you have
int numPrimes=25;

//Store the given input
int input=in;
//It is going to store every number which is divided
int numbers[100];
//It is going to store every number which is divider
int deviders[100];
//The number of divide operation
int counter=0;

//Start dividing
for(int i=0;i<numPrimes;i++){
	
	//Divide until see a fractional number
	while(input%primes[i]==0){
		//Store them
		numbers[counter]=input;
		deviders[counter]= primes[i];
		input = input/primes[i];
		counter++;
		
		}
	}
	//Output for the user
	printf("\n%9s%d\n","Prime factorization of ",in);
for(int i=0;i<counter;i++){
	//Print the values
	printf("\n%9d|%-3d",numbers[i],deviders[i]);

	}
	//If 1 the means given has a prime number which is bigger then our database
	if(input!=1){
	printf("\n%9d| The number is prime",input);
}else{
	printf("\n%9d|",input);
	}
//Open a file
FILE * fp;
   int i;
   fp = fopen ("./Desktop/Project/primef.txt","w");

	//Write it on a .txt
	fprintf(fp,"\n%9s%d\n","Prime factorization of ",in);
   
   for(i = 0; i < counter;i++){
       	//Write the values on a .txt
       	fprintf(fp,"\n%9d|%-3d",numbers[i],deviders[i]);

	}
	if(input!=1){
	fprintf(fp,"\n%9d| The number is prime",input);
}else{
	fprintf(fp,"\n%9d|",input);
   }
 
//Close the file
   fclose (fp);

}
