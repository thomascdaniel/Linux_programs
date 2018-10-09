//Inter process communication using pipe
//parent process writes data and child process reads the data

#include <stdio.h>
#include <unistd.h>

void do_child(int data_pipe[]){
	int c;
	int rc;
	close(data_pipe[1]);
	while((rc = read(data_pipe[0], &c, 1)) > 0){
		putchar(c);
	}
}

void do_parent(int data_pipe[]){
	int c;
	int rc;
	close(data_pipe[0]);
	while((c=getchar()) > 0){
		rc = write(data_pipe[1], &c, 1);
		if(rc == -1){
			perror("PARENT : WRITE");
			close(data_pipe[1]);
		}
	}
close(data_pipe[1]);	
}

int main(int argc, char* argv[]){
	int data_pipe[2];
	int pid;
	int rc;
	rc = pipe(data_pipe);
	if(rc == -1){
		perror("ERROR IN CREATING PIPE");
	}
	pid=fork();
	switch(pid){
		case -1: perror("ERROR IN CREATING CHILD PROCESS");
		break;

		case 0: do_child(data_pipe);
				break;
		default: do_parent(data_pipe);		
	}
	return 0;
}