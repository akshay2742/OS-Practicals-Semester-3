#include<stdio.h>
#include<stdlib.h>
int main()
{
  char a[1000];
  char b[1000];
  FILE *fptr;
  FILE *fpt;
  fptr=fopen("Program.txt","w");
  if(fptr==NULL)
  {
  	printf("Error opening file");
  	exit(1);
  }
  printf("Enter a sentence\n");
  scanf("%s",a);
    
  fprintf(fptr,"%s",a);
  fclose(fptr);
  fpt=fopen("Program.txt","r");
  if(fptr==NULL)
  {
  	printf("Error opening file");
  	exit(1);
  }
  fscanf(fpt,"%[^\t]",b);
  printf("Text in the file is:\n%s",b);
  
  fclose(fpt);
  







}
