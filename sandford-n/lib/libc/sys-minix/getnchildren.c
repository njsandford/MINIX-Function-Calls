/* Natalie Sandford - 130031439 */

#include <lib.h>
#include <unistd.h>

int getnchildren(pid_t pid) {
    message m; // Minix message to pass parameters to a system call
	
	// ERRNO is set to ESRCH if the pid supplied is not a valid process, and the function returns -1.
    if (pid < 1) {
		errno = ESRCH;
		return -1;
	}
    
	m.m1_i1 = (int) pid; // Set first integer of message to pid, cast to int.

	// Invoke the system call and return the integer value.
	return _syscall(PM_PROC_NR, GETNCHILDREN, &m);
}