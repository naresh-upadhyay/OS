#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkcall() 
{ 
	if (fork() == 0) 
		printf("Child!:- %d\n",getpid()); 

	else
		printf("Parent!:- %d\n",fork()); 
} 
int main() 
{ 
	forkcall(); 
	return 0; 
} 
