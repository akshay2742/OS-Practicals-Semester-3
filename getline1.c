#include<stdio.h>
#include<stdlib.h>
void getline(FILE* ptr)
{
    char str;
    while(1)
    {
        str=fgetc(ptr);
        if(str=='\n' || feof(ptr))
        {
            break;
        }
        printf("%c",str);
    }
    
}
int main()
{
    FILE* inp;
    inp= fopen("getline.txt","r");
    
    getline(inp);
}