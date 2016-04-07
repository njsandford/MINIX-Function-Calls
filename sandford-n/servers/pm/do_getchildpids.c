/* Natalie Sandford - 130031439 */

#include <stdio.h>
#include "pm.h"
#include "mproc.h"

int do_getchildpids() {
	pid_t pid = (pid_t) m_in.m1_i1; // Set pid to first integer of incoming message, cast to pid.
	int nchildren = m_in.m1_i2; // Set nchildren to second integer of incoming message.
	vir_bytes childpids = (vir_bytes) m_in.m1_p1; // Set childpids to first pointer of incoming message, cast to vir_bytes.
	
	// Initialise local variables.
	pid_t child_pid;
	int parent_idx;
	pid_t parent_pid;
	int child_count = 0;
	pid_t childpids_arr[nchildren]; // Local childpids_arr array to be coppied to the childpids array.
	
	// Iterate through the list of processes, stop if nchildren exceeds the child count.
    for (int i = 0; i < NR_PROCS && child_count < nchildren; i++) {
		
		child_pid = mproc[i].mp_pid; // Set the child pid to the pid of the current process.
		parent_idx = mproc[i].mp_parent; // Set the parent index to the index of the current process' parent.
		parent_pid = mproc[parent_idx].mp_pid; // Set the parent pid to the pid of the process at position parent_idx.

		// Check that the parent of the current process is the pid recieved by the message.
		if (parent_pid == pid) {
			// Check that the child pid is not 0.
			if ((child_pid != 0) ) {
				// Add the child process to the local array and increment the child counter.
				childpids_arr[child_count] = child_pid;
				child_count++;
			}
		}
    }
	
	// Copy the local childpids_arr array to the childpids array, and pass result to an int.
    int result = sys_vircopy(SELF, (vir_bytes)&childpids_arr, who_e, childpids, sizeof(childpids_arr));
	
	// If sys_vircopy fails, return the result.
	if (result != 0) {
		errno = EINTR; // ERRNO is set to EINTR if sys_vircopy fails.
		return result;
	}
	
	// Return the number of children copied to the array.
	return child_count;
}