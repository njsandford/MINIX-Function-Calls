/* Natalie Sandford - 130031439 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2)
        exit(1); // At least 1 integer parameter is expected to test program.
        
    // Convert input into an int and store as a pid_t.
	pid_t pid = atoi(argv[1]);
    
	// Call the system call and store result as an int.
	int nchildren = getnchildren(pid);
	
    // If an error is present, print an appropriate user message.
    if (errno == ESRCH) {
		printf("PID specified must not be less than 1: %s\n", strerror(errno));
	}
	else {
		// Print out the number of children returned by the system call.
		printf("nchildren: %d\n", nchildren);
	}
}