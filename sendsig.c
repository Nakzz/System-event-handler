///////////////////////////////////////////////////////////////////////////////
//
// Author:           Ajmain Naqib
// Email:            naqib@wisc.edu
//
// Online sources:   
///////////////////////////////////////////////////////////////////////////////

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

//	printf("%d", argc);
//	printf("%s, %d, %d", argv[1], strcmp(argv[1], "-i"), strcmp(argv[1], "-u"));

	//making sure exactly 2 proper instructions are passed in
	if(argc ==3 && ( strcmp(argv[1], "-i") !=0 || strcmp(argv[1], "-u") !=0)){
		printf("Usage: <signal type> <pid> \n");
	} else {
	
 	int pid =atoi(argv[2]); // parse the int
	//printf("%s, %d \n",argv[1], pid );
	
	//proper action handling
		if(strcmp(argv[1], "-i") ==0)
			kill(pid, SIGINT);

		 if(strcmp(argv[1], "-u") ==0)
                        kill(pid, SIGUSR1);
	}

	exit(0);

}
