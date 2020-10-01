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

//same program in c++
#include<iostream>
#include<sys/stat.h>
#include<time.h>
using namespace std;

int main(int argc, char* argv[])
{
  int i;
  struct stat s;

  if(argc<2)
  {
    cout<<"No filename entered!"<<endl;
    return -1;
  }
  else
  {
    for(i=1; i<argc; i++)
    {
      cout<<"File Name: "<<argv[i]<<endl;
      if(stat(argv[i], &s) < 0)
        cout<<"Error in obtaining file information!"<<endl;
      else
      {
        cout<<"\nOwner ID: "<<s.st_uid<<endl;
        cout<<"Group ID: "<<s.st_gid<<endl;

        //printing the file type using 1st bit of modes
        cout<<"\nFile type: ";
        switch(s.st_mode & S_IFMT)
        {
          case S_IFBLK:
            cout<<"Block Device"<<endl;
            break;
          case S_IFCHR:
            cout<<"Character Device"<<endl;
            break;
          case S_IFDIR:
            cout<<"Directory"<<endl;
            break;
          case S_IFIFO:
            cout<<"FIFO/pipe"<<endl;
            break;
          case S_IFLNK:
            cout<<"Symlink"<<endl;
            break;
          case S_IFREG:
            cout<<"Regular File"<<endl;
            break;
          case S_IFSOCK:
            cout<<"Socket"<<endl;
            break;
          default:
            cout<<"Unknown"<<endl;
            break;
        }

        cout<<"Permissions: "<<oct<<(s.st_mode &(S_IRWXU | S_IRWXG | S_IRWXO))<<endl; //extracting last 9 bits
        cout<<"Last access time: "<<ctime(&s.st_atime)<<endl;
        cout<<"File size: "<<s.st_size<<endl;
        cout<<"File size in blocks: "<<s.st_blksize<<endl;
      }
    }
  }
  return 0;
}
