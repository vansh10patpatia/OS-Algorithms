#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    char writeMessages[2][100] = {"Hi", "Hello"};
    char readMessages[100];
    int p[2];
    pipe(p);
    int pid = fork();
    if(pid > 0)          //parent process
    { 
        write(p[1], writeMessages[0], sizeof(writeMessages[0]));
        printf("Parent process writing to child process : %s\n",writeMessages[0]);
        write(p[1], writeMessages[1], sizeof(writeMessages[1]));
        printf("Parent process writing to child process : %s\n",writeMessages[1]);
    } 
    else if(pid == 0)    //child
    { 
        read(p[0], readMessages, sizeof(readMessages));
        printf("Child process reading from parent process : %s\n",readMessages);
        read(p[0], readMessages, sizeof(readMessages));
        printf("Child process reading from parent process : %s\n",readMessages);
    }
}