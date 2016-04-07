#include <lib.h>
#include <stdio.h>
#include <stdlib.h>

struct user_pidinfo {
    int idx;
    pid_t pid;
    int parent_idx;
} user_pidinfo[NR_PROCS];

int main(int argc, char **argv) {
    message m;
    m.m1_p1 = (char *) user_pidinfo;
    
    int status = _syscall(PM_PROC_NR, PIDINFO, &m);
    
    printf("status: %d\n", status);
    
    for (int i = 0; i < NR_PROCS; i++) 
        if (user_pidinfo[i].pid)
            printf("idx: %d, pid: %u, parent_idx: %d\n",
                    user_pidinfo[i].idx, user_pidinfo[i].pid, 
                    user_pidinfo[i].parent_idx);
}
