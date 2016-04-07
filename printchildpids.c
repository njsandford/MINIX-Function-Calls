/* Natalie Sandford - 130031439 */

#include <lib.h>
#include <unistd.h>

int printchildpids(pid_t pid) {
    message m; // Minix message to pass parameters to a system call
	
    if (pid < 1) {
		errno = ESRCH; // ERRNO is set to ESRCH if the pid supplied is not a valid process.
		return -1;
	}
	
	m.m1_i1 = (int) pid; // Set first integer of message to pid, cast to int.
	
	return _syscall(PM_PROC_NR, PRINTCHILDPIDS, &m); // Invoke the system call and return the integer value.
}