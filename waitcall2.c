#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 

void waitfunct() 
{ 
	int stat1; 
	if (fork() == 0) 
		exit(12); 
	else
		wait(&stat1); 
        
	if (WIFEXITED(stat1)) 
		printf("Exit status: %d\n", WEXITSTATUS(stat1)); 
	else if (WIFSIGNALED(stat1)) 
        printf("exit :%d\n",WTERMSIG(stat1));
} 
int main() 
{ 
	waitfunct(); 
	return 0; 
} 
