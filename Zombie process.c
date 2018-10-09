// A C program to demonstrate zombie process
// Child becomes zombie as parent is sleeping when child process exits.

#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
// Fork returns process id in parent process
pid_t child_pid=fork();

//Parent Process
if(child_pid>0)
sleep(50);

//CHILD process
else
exit(0);

return 0;
}
