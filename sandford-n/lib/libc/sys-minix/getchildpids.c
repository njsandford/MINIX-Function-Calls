/* Natalie Sandford - 130031439 */

#include <lib.h>
#include <unistd.h>

int getchildpids(pid_t pid, int nchildren, pid_t *childpids) {
    message m; // Minix message to pass parameters to a system call
    
	if (pid < 1) {
		errno = ESRCH; // ERRNO is set to ESRCH if the pid supplied is not a valid process.
		return -1;
	}
	else if ((nchildren < 0) || (childpids == 0)) {
		errno = EINVAL; // ERRNO is set to EINVAL if the number of children is < 0, or if the array pointer is null.
		return -1;
	}
	else if (nchildren == 0) {
		return 0; // Return 0 if the number of chilren is 0.
	}

	m.m1_i1 = (int) pid; // Set first integer of message to pid, cast to int.
	m.m1_i2 = nchildren; // Set second integer of message to nchildren.
	m.m1_p1 = (char *) childpids; // Set first pointer of message to childpids, cast to char *.
		
	// Invoke the system call and return the integer value.
	return _syscall(PM_PROC_NR, GETCHILDPIDS, &m);
}