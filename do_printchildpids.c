/* Natalie Sandford - 130031439 */

#include <stdio.h>
#include "pm.h"
#include "mproc.h"

int do_printchildpids() {
	pid_t pid = (pid_t) m_in.m1_i1;// Set pid to first integer of incoming message, cast to pid.
	
	// Initialise local variables.
	pid_t child_pid;
	int parent_idx;
	pid_t parent_pid;
	
	// Print message to show that the system call has been called.
	printf("Searching for children of process: %u\n", pid);

	// Iterate through the list of processes.
	for (int i = 0; i < NR_PROCS; i++) {
		
		child_pid = mproc[i].mp_pid; // Set the child pid to the pid of the current process.
		parent_idx = mproc[i].mp_parent; // Set the parent index to the index of the current process' parent.
		parent_pid = mproc[parent_idx].mp_pid; // Set the parent pid to the pid of the process at position parent_idx.
		
		// Check that the parent of the current process is the pid recieved by the message.
		if (parent_pid == pid) {
			// Check that the child pid is not 0.
			if (child_pid != 0) {
				// Print the pid of the child.
				printf("%u\n", child_pid);
			}
		}
	}	
	
	// Return 0 on sucess.
	return 0;
}