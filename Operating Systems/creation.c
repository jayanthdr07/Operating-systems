#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int main() { 
pid_t pid; 
// Create a new process 
pid = fork(); 
if (pid < 0) { 
// Fork failed 
perror("fork failed"); 
exit(1); 
}  
    else if (pid == 0) { 
        // Child process 
        printf("Child process (PID: %d)\n", getpid()); 
 
        // Replace child process with "ls -l" 
        char *args[] = {"ls", "-l", NULL}; 
        execvp(args[0], args); 
 
        // If execvp returns, it must have failed 
        perror("exec failed"); 
        exit(1); 
    }  
    else { 
        // Parent process 
        printf("Parent process (PID: %d), waiting for child...\n", getpid()); 
        wait(NULL);  // Wait for child to finish 
        printf("Child finished.\n"); 
    } 
 
    return 0; 
} 
 