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
	
	// Set nchildren to the result of the getnchildren system call.
	int nchildren = getnchildren(pid);

	// Create a local pid_t array to store the child pids in.
    pid_t childpids[nchildren];
	
	// Call the system call and store result as an int.
	int result = getchildpids(pid, nchildren, childpids);
	
	// If an error is present, print an appropriate user message.
    if (errno == ESRCH) {
		printf("PID specified must not be less than 1: %s\n", strerror(errno));
	}
	else if (errno == EINVAL) {
		printf("Ensure that 'nchildren' is at least 0: %s\n", strerror(errno));
	}
	else {
		// Iterate through the childpids array and print out each child pid. 
		for (int i = 0; i < nchildren; i++) {
			printf("%u\n", childpids[i]);
		}
		// Print out the number of children returned by the system call.
		printf("nchildren: %d\n", result);
	}
	
}