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
  
  //cpp
  #include<iostream>
#include<fstream>
#include<string>
using namespace std;

void my_copy()
{
  fstream file_r, file_w;
  string fname_r, fname_w;
  char ch, delim = '$';

  cout<<"Enter the file name to read the content: ";
  cin>>fname_r;
  file_r.open(fname_r);
  if(!file_r)
  {
    cout<<"File not found!!"<<endl;
    exit(1);
  }

  cout<<"Enter the file name to write the content: ";
  cin>>fname_w;
  file_w.open(fname_w);
  if(!file_w)
  {
    cout<<"File not found!!"<<endl;
    exit(1);
  }

  if(file_r && file_w)
  {
    while(ch != delim)
    {
      file_r.get(ch);
      if(ch == '$')
        break;
      file_w<<ch;
    }
    cout<<"\nContent successfully copied!!"<<endl;
  }
  else
    cout<<"Content not copied!!"<<endl;

  file_r.close();
  file_w.close();
}

int main()
{
  cout<<"Program to copy contents of a file to another"<<endl;
  my_copy();
  return 0;
}

  







}
