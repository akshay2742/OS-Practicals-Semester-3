#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid,p;
    p=fork();
    pid=getpid();
	if(p < 0)
	{
        fprintf(stderr,"Fork Failed");
		return 1;
	}
    printf("Output of Fork id: %d \n",p);
    printf("process id is:%d \n",pid);
    return 0;
}
_____________________________

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid;
	/* fork a child process */
	pid = fork();
    if (pid < 0)
    {
		/* error occurred */
		fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
		/* child process */
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
        printf("Parent Process.");
    }
    return 0;
}

_________________________________

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		cout<<"No process entered";
	}
	else if(pid==0)
	{
		execlp("/bin/ls","ls",NULL);
		cout<<"child process";
	}
	else
	{
		cout<<"parent process";
	}
	return 0;
}

______________________________________

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
int main()
{
    pid_t pid;
	/* fork a child process */
	pid = fork();
    if (pid < 0)
    {
		/* error occurred */
		fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
		/* child process */
	        printf("Child is going to sleep for 5 seconds");
	        sleep(5);
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
		/* parent process */
		/* parent will wait for the child to complete */
	        printf("Parent will wait for the child process as it sleeps for 5 seconds");
		wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
