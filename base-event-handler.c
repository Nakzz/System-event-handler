
///////////////////////////////////////////////////////////////////////////////
// Author:           Ajmain Naqib
// Email:            naqib@wisc.edu
//
// Online sources:   
//                  
//                 
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

static int alarmTime= 3;
static int sigUser1Count =0;

/**
 * Handles SIGALRM signal by printing out some infomation
 * about the process and time
 *
 * */
void sig_handler(){
    pid_t pid = getpid();
      time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

    printf("PID: %d | Current Time: %s", pid, asctime(timeinfo));
    alarm(alarmTime);
    
}

/**
 * Handles SIGUSR1 signals from the system
 *
 * signum: the signal number that raises the function
 *
 **/
void sigUSR1_handler(int signum){

	if(signum == SIGUSR1){
	printf("SIGUSR1 caught!\n");
	sigUser1Count++;
	}
}

/**
 * Handles SIGINT signals from system and prints appropritate information
 *
 **/

void sigINT_handler(){
	printf("SIGINT received \n SIGUSR1 was received %d times. Exiting now.\n", sigUser1Count);
	exit(0);
	
}

int main(){
    
	//all the sigactions
    struct sigaction sa;
    struct sigaction saU1;
    struct sigaction saINT;

    //memory allocation
    memset(&saU1, 0, sizeof(saU1));
    memset(&sa, 0, sizeof(sa));
    memset(&saINT, 0, sizeof(saINT));

    //assigning proper signal handler to signals
    sa.sa_handler = sig_handler;
    if(sigaction(SIGALRM, &sa, NULL) != 0){
        printf("Failed to bind handler.\n");
        exit(1);
    }
    saU1.sa_handler = sigUSR1_handler;
    if(sigaction(SIGUSR1, &saU1, NULL) != 0){
        printf("Failed to bind handler.\n");
        exit(1);
    }
        saINT.sa_handler = sigINT_handler;
    if(sigaction(SIGINT, &saINT, NULL) != 0){
        printf("Failed to bind handler.\n");
        exit(1);
    }



    printf("PID and time will be printed every 3 seconds.\nEnter ^C to end the program.\n");
    alarm(alarmTime);
    while(1); // inf loop
    return 0;
}
