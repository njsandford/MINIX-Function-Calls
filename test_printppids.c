#include <unistd.h>
#include <stdlib.h>
#include <lib.h>
#include <stdio.h>

int main(void) {
    message m;  // Minix uses message to pass parameters to a system call
    
    _syscall(PM_PROC_NR, PRINTPPIDS, &m);
        /* _syscall leads to the system server identified by PM_PRO_NR (the PM
         * server process) invoking the function identified by call number 
         * PRINTMSG with parameters in the message copied to address &m
         */   
}

/*
int main(int argc, char **argv) {
    if (argc < 3)
        exit(1);    // expecting at least 1 integer parameter to test program
        
    int idx = atoi(argv[1]);
    int n = atoi(argv[2]);
	
    printmsg(i);
}*/