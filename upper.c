#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void uppers(char str2[]);


void uppers(char str2[]){

//Declera a String
char str[strlen(str2)];


//Copy the input string
strcpy(str, str2);
//At space to end
strcat(str," ");

//Declare a variable which going to store the right indices
int index[strlen(str2)];
//Declare a variable for number of right indices
int counter=0;


	
//Start searching the input String line by line
for(int i=0;i<strlen(str2);i++){
	//Until it see a uppercase letter
	while((str[i]!='\0' && str[i]>64 && str[i]<91)){
		index[counter]=i;
		counter++;
		break;
		}
	}
	//First index and the last index of the name
	int firstLetter;
	int lastLetter;
	//Declare a variable which going to the names
	char names[strlen(str2)][strlen(str2)];
	int nameCounter=0;
	
	//Malloc a location for names
	for(int i=0;i<strlen(str2);i++){
		for(int j=0;j<strlen(str2);j++){
			names[i][j]='\0';
			}
		}
	//Malloc a location for indices
	for(int i=counter;i<strlen(str2);i++){
		index[i]=0;
		}
	
	//Start storing names on the variable
	for(int i=0;i<counter;i++){
		int a= 0;
		firstLetter=index[i];
		lastLetter=index[i+1];
		if(lastLetter>0){
			
			for(int j=firstLetter;j<lastLetter;j++){
				names[nameCounter][a]= str[j];
				a++;
				}
				nameCounter++;
			}else if(lastLetter==0){
						lastLetter=strlen(str);
						
				for(int y=firstLetter; y<lastLetter; y++){
				
					
					names[nameCounter][a]= str[y];
					a++;
				
			}
			nameCounter++;
		}
	}
	
	/*for(int i=0; i<nameCounter-1; i++){
			int smallindex=i;
			for(int j= i+1; j<nameCounter; j++){
				if(names[smallindex][0]>names[j][0]){
					smallindex=j;
					}
				
			}
			for(int j=0; j<100; j++){
				char name[100];
				//name[j]=names[i][j];
				swap(&names[i][j], &name[j]);
				//memcpy(&names[i][j], &name[j], 1);
				//names[smallindex][j]=names[i][j];
				swap(&names[i][j], &names[smallindex][j]);
				//memcpy(&names[i][j], &names[smallindex][j], 1);
				//names[i][j]=name[j];
				swap(&name[j], &names[i][j]);
				//memcpy(&name[j], &names[i][j], 1);
			}
		
		}*/
	
		//Declare a file
		FILE *fp;
		
		fp = fopen("./Desktop/Project/upperCase.txt", "w");
	//Write those names to .txt
	for(int k=0;k<nameCounter+1;k++){
		printf("\n%s",names[k]);
		fprintf(fp,"%s",names[k]);
		fprintf(fp, "\n");
		}
	//Close the file	
	fclose(fp);
}
