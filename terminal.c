#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include "primes.h"
#include "upper.h"

int main(int argc, char ** argv){
	
	//Declaring a variable for shell scripts
	FILE *fp;
	//Declaring String for print 
	char line[128];
	//Declaring a variable for number of lines
	int linenr;
	
	
	//Declaring the input String of the termianl
	char str1[100];
	//Declaring the String which going store the input line by line
	char newString[10][10]; 
	//Oppening title of the terminal
	printf("\n┏┓┏┓┏┓╋╋┏┓╋╋╋╋╋╋╋╋╋╋╋╋╋┏━━━━┓╋╋┏━━━┓╋╋╋╋╋╋┏┓\n┃┃┃┃┃┃╋╋┃┃╋╋╋╋╋╋╋╋╋╋╋╋╋┃┏┓┏┓┃╋╋┃┏━┓┃╋╋╋╋╋┏┛┗┓\n┃┃┃┃┃┣━━┫┃┏━━┳━━┳┓┏┳━━┓┗┛┃┃┣┻━┓┃┗━━┳┓╋┏┳━┻┓┏╋━━┳┓┏┓\n┃┗┛┗┛┃┃━┫┃┃┏━┫┏┓┃┗┛┃┃━┫╋╋┃┃┃┏┓┃┗━━┓┃┃╋┃┃━━┫┃┃┃━┫┗┛┃\n┗┓┏┓┏┫┃━┫┗┫┗━┫┗┛┃┃┃┃┃━┫╋╋┃┃┃┗┛┃┃┗━┛┃┗━┛┣━━┃┗┫┃━┫┃┃┃\n╋┗┛┗┛┗━━┻━┻━━┻━━┻┻┻┻━━┛╋╋┗┛┗━━┛┗━━━┻━┓┏┻━━┻━┻━━┻┻┻┛\n╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┏━┛┃\n╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┗━━┛");
   
	do{
   
    int i,j,ctr;
       //Formatting
       printf("\n\nENTER A COMMAND :\n");
       //Formatting
       printf("================>> ");    
	
    fgets(str1, sizeof(str1), stdin);	
	//Seperating the input by looking spaces
    j=0; ctr=0;
    for(i=0;i<=(strlen(str1));i++)
    {
        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  
            j=0;    
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }

	//Check the command argument of input
	if((strncmp(newString[0],"guess",5))==0){
		//Neccesary Error conditions for the command
		if(atoi(newString[1])<0 || (atoi(newString[1])==0)){
			printf("\n ERROR: Enter a valid argument!\n");
			printf("\n guess *positive_range\n");
			printf("\n COMMAND: guide ===> For more information.\n");
			}
		//Run the command if there is no error
		else{
		//Preparing the input for shell script
		char input[80];
		strcpy(input,"./Desktop/Project/guess.sh ");
		strcat(input,newString[1]);
		//Run the shell script
		fp=popen(input,"r");
		if (fp== NULL){
			perror(argv[0]);
			return 1;
			}
		linenr=1;
		while(fgets(line,128,fp) != NULL){
			//Output of the shell script
			printf("%s",line);
			linenr++;
			}
		//Close the script after the operation
		pclose(fp);
	}
	
	}
	//Check the command argument of input
	else if((strncmp(newString[0],"bmi",3))==0){
		//Neccesary Error conditions for the command
		if(atoi(newString[1])<=0 || atoi(newString[2])<=0 || (atoi(newString[1]))>(atoi(newString[2]))){
			printf("\n ERROR: Enter a valid argument!");
			printf("\n bmi *weight(kg) *height(cm)");
			printf("\n COMMAND: guide ===> For more information.");
			}
		//Run the command if there is no error
		else{
		char input[80];
		strcpy(input,"./Desktop/Project/bmi.sh ");
		strcat(input,newString[1]);
		strcat(input," ");
		strcat(input,newString[2]);
		//Run the shell script
		fp=popen(input,"r");
	
	if (fp== NULL){
		perror(argv[0]);
		return 1;
		}
	linenr=1;
	while(fgets(line,128,fp) != NULL){
		//Output of the shell script
		printf("%s",line);
		linenr++;
		}
	//Close the script after the operation
	pclose(fp);
	}
	}
	//Check the command argument of input
	else if((strncmp(newString[0],"primef",3))==0){
		//Neccesary Error conditions for the command
		if(atoi(newString[1])<=0){
			printf("\n ERROR: Enter a valid argument!");
			printf("\n primef *positive_number");
			printf("\n COMMAND: guide ===> For more information.");
			}
		//Run the command if there is no error
		else{
			primes(atoi(newString[1]));
		}
		}
	//Check the command argument of input
	else if((strncmp(newString[0],"upper",3))==0){
		//Run the command if there is no error
		uppers(newString[1]);
		}
	//Guide command of the terminal
	else if((strncmp(newString[0],"guide",5))==0){
		//Guidelines
		printf("\nbmi *weight(kg) *height(cm) => Calculates the body mass index of given input.\n");
		printf("\nguess *positive_range =======> System picking a number between given range.\n");
		printf("\nprimef *positive_number =====> Prime factorization of given nnumber.\n");
		printf("\nupper *str ==================> Seperating words by looking uppercase letters.\n");
		printf("\nexit ========================> Quit from the system.\n");
		}
	//The exit condition for the terminal
	else if((strncmp(newString[0],"exit",4))!=0){
		printf("Given command is not valid => %s",newString[0]);
		printf("\nCOMMAND: guide ===> For more information.");
		}
//Run the terminal untill input==exit
}while(strncmp(str1,"exit",4)!=0);



	return 0;
	
}
