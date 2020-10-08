#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char ch, filein[20], fileout[20];
   FILE *src, *dest;
 
   printf("Enter name of file to copy\n");
   scanf("%s", filein);
 
   fopen(filein, "r");
 
   if( !filein )
   {
      printf("Error opening source file\n");
      exit(0);
   }
 
   printf("Enter name of destination file\n");
   scanf("%s", fileout);
 
   fopen(fileout, "w");
 
   if( !fileout )
   {
      
      printf("Error opening destination file\n");
      exit(0);
   }
 
   while( ( ch = fgetc(src) ) != EOF )
      fputc(ch, dest);
 
   printf("File copied successfully.\n");
 
   fclose(src);
   fclose(dest);
 
   return 0;
}

//cpp
//Program to copy contents of a file to another
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void my_copy()
{
  fstream file_r, file_w;
  char fname_r[15], fname_w[15];
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



