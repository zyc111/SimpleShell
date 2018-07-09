#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void get_Cmd(char *cmd[]);
void execute_Cmd (char *cmd[]);
void PrinT();

int main()
{
	char *cmd[10];

	while(1){
		get_Cmd(cmd);
		execute_Cmd(cmd);
		if(strcmp(cmd[0], "exit") == 0){
			exit(0);
		}
	}
	return 0;
}

void PrinT()
{
	time_t ct;
	struct tm * CurrTime;
	time (&ct);
	CurrTime = localtime (&ct);
	printf("%d:%d:%d# ",CurrTime->tm_hour, CurrTime->tm_min, CurrTime->tm_sec);
}

void get_Cmd (*cmd[])
{
	char cmd_in [100], *tempa[100], *token;
	int rtime = 1, i = 0, j =0;
	
	while(rtime){
		PrinT();
		fgets(cmd_in, 100, stdin);
		rtime = 0;
	}
	
	token = strtok(cmd_in, " \n");
	while(token != NULL){
		tempa[i] = strdup(token);
		token = strtok(NULL, "\n");
		i++;
		cmd[i] = NULL;
		if(j < i){
			cmd[j] = tempa[j];
			j++;		
		}
	}
}

void execute_Cmd (*cmd[])
{
	pid_t pid = fork();
	if (pid != 0){
		int Child;
        	waitpid(pid, &Child, 0);
	}
	else{
		execvp(cmd[0], cmd);
	}
}



