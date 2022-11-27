#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>


int main() {

  pid_t pid = 0;
  //int status = 0;

  for(int i=0; i<2;++i){
    pid = fork();

    if (pid < 0){
      printf("Error, child has not been created\n");
    }

    if (pid==0){
      if (i==0){
        char *argv1[2] = {"./summation.exe", NULL};
        execv("./summation.exe", argv1);

        exit(0);
      }

      else{//child 2
      //list available directory files
        char *argv2[2] = {"./fact.exe", NULL};
        execv("./fact.exe", argv2);

        exit(0);
      }
    }

  else{

    pid_t status = waitpid(pid, &status, 0);

    if (status > 0){

       printf("\nChild is terminated\n");

    }

    else{
       printf("\nwaitpid failed\n");}}}
  return 0;
}

