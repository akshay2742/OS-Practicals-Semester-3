#include<stdio.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
   int i;
   FILE *f;
   struct stat s;
   if(argc<2){
    printf("No file name entered");
   }
   f=fopen(argv[1],"r");
   if(!f){
    printf("Error opening file");
    exit(0);
   }
   else{
       for(i=0;i<argc;i++){
          printf("For file: %s",argv[i]);
          printf("\nOwner ID: %d",s.st_uid);
          printf("\nGroup ID: %d",s.st_gid);
          printf("\nFileSize: %d",s.st_size);
          printf("Last access time: %s",ctime(&s.st_atime));
          printf("Permissions: %o",s.st_mode & (S_IRWXU));  // in octal

   }
   }

}
