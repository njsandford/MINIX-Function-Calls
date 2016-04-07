#include <stdio.h>
#include "pm.h"             // for various global variables
#include "mproc.h"          // for process table mproc

int do_printppids() {
	int idx = m_in.m1_i1;          // replace ... with assignment from a field of incoming message
	int n = m_in.m1_i1;            // replace ... with assignment from a field of incoming message


	/*
	 * Note: when implementing the following outline code you must make sure
	 * that idx is within the valid range for the process table,
	 * otherwise you will index beyond the end of the array and
	 * potentially crash Minix
	 */

	if (idx > NR_PROCS) {
		exit(ERROR);
	}

	
	while (n > 0) {
		pid_t pid = mproc[idx].mp_pid;// get pid of process at position "idx" in process table
		printf("Searcing for parents of process: %u", pid);
	
		if (pid) { 
			// pid is not 0
			int parent_idx = mproc[idx].mp_parent; 
			pid_t ppid = mproc[parent_idx].mp_pid; // get pid of parent (ppid) of process at "idx" in table
			printf("%u %u\n", pid, ppid); // print the pid and ppid separated by a space on a single line
			n--;            // found non zero pid
		}
	
		idx++;              // move to next idx, until found n non-zero pids
	}

	return(idx);// return the next index in table
}