#include<stdio.h>

int main()
{	
	int ch;
	printf("1.Print Kernel version");
	printf("\n2.Print CPU info");
	printf("\n3.Print Memory info");
	printf("\nEnter your choice : ");	scanf("%d",&ch);
	
	if(ch==1)
	{
		system("cat /proc/version|awk ' BEGIN{ echo \"Kernel version :\"}{print $1,$3}'");
	}
	else
	{
		if(ch==2)
		{
						
			system("cat /proc/cpuinfo|awk 'NR==5'|awk ' BEGIN{ print \"CPU Type :\"}{print $4,$5,$6,$8,$9}'");
			system("cat /proc/cpuinfo|awk 'NR==4'|awk ' BEGIN{ print \"Model :\"}{print $3}'");		
		}
		else
		{
			system("cat /proc/meminfo|awk 'NR==1'|awk ' BEGIN{ print \"Configured Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==2'|awk ' BEGIN{ print \"Used Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==3'|awk ' BEGIN{ print \"Available Memory :\"}{print $2,$3}'");
		}
	}

	return 0;
}

//cpp
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc<2)
  {
    cout<<"Press: "<<endl;
    cout<<"1 to Print Kernel Version"<<endl;
    cout<<"2 to Print CPU Info"<<endl;
    cout<<"3 to Print Memory Info"<<endl;
    cout<<"Example: .\\proc 1 will print the kernel version"<<endl;
    cout<<"Example: .\\proc 1 3 will print the kernal version and the memory info"<<endl;
  }

  for(int i=1; i<argc; i++)
  {
    int sw = stoi(argv[i]);
    switch(sw)
    {
      case 1:
        cout<<"\nKernel Version: "<<endl;
        system("cat /proc/version|awk '{print $1, $2, $3}'");
        break;
      case 2:
        cout<<"\nCPU Info: "<<endl;
        cout<<"CPU type: "<<endl;
        system("cat /proc/cpuinfo|awk 'NR == 3'");
        system("cat /proc/cpuinfo|awk 'NR == 8'");
        system("cat /proc/cpuinfo|awk 'NR == 13'");
        cout<<"\nCPU Mode: "<<endl;
        system("cat /proc/cpuinfo|awk 'NR == 5'");
        break;
      case 3:
        cout<<"\nMemory Info: "<<endl;
        cout<<"Configured Memory: "<<endl;
        system("cat /proc/meminfo|awk 'NR == 1'|awk '{print $2, $3}'");
        cout<<"\nFree Memory: "<<endl;
        system("cat /proc/meminfo|awk 'NR == 2'|awk '{print $2, $3}'");
        break;
      default:
        cout<<"Wrong Input!"<<endl;
    }
  }
  return 0;
}

