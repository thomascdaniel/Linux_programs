//This program creates two child processes displaying some lines
//The parent waits until all the child processes are done and exits

#include <stdio.h>
#include  <stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COUNT 100
#define BUF_SIZE 100

void ChildProcess(char []); 	/*Child process prototype*/

void main(void){

	pid_t pid1, pid2, pid;
	int status;
	int i;
	char buf[BUF_SIZE];

	printf("****Parent is about to fork process 1*****\n");
	if((pid1=fork()) < 0){
		printf("Failed to fork the process 1\n");
		exit(1);
	}
		else if(pid1 == 0){
			ChildProcess("First Child");
		}

	printf("****Parent is about to fork process 2*****\n");
	if((pid2=fork()) < 0){
		printf("Failed to fork the process 2\n");
		exit(1);
	}
		else if(pid2 == 0){
			ChildProcess("Second Child");
		}

	sprintf(buf, "****Parent enters waiting state*****....\n");	
	write(1, buf, strlen(buf));
	pid = wait(&status);
	sprintf(buf, "****Parent detects process %d was done*****....\n",pid);
	write(1, buf, strlen(buf));
	pid = wait(&status);
	printf("***Parent detects process %d is done***\n",pid);
	printf("***Parent exists***\n");
	exit(0);

}

void ChildProcess(char *number){
	pid_t pid;
	int i;
	char buf[BUF_SIZE];
	pid = getpid();
	sprintf(buf, "%s Child process starts (pid = %d)\n",number, pid);
	write(1, buf, strlen(buf));
	for(i = 1; i<= MAX_COUNT; i++){
		sprintf(buf, "%s Child output,, value = %d\n",number, i);
		write(1, buf,strlen(buf));
	}
	sprintf(buf, "%s Child (pid = %d) is about to exit\n",number, pid);
	write(1, buf, strlen(buf));
	exit(0);
}