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