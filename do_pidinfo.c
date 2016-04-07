#include <stdio.h>
#include "pm.h"             // for glo.h:  mp, call_nr, who_p etc.
#include "mproc.h"          // for proc table

struct pidinfo {
    int idx;             /* this process' index in table */
    pid_t pid;           /* this process' pid */
    int parent_idx;      /* index of this process' parent in table */
} pidinfo[NR_PROCS];


int do_pidinfo() {
    vir_bytes pidinfo_arr= (vir_bytes) m_in.m1_p1;

    for (int i = 0; i < NR_PROCS; i++) {
        if (mproc[i].mp_pid)
            printf("i: %d, mp_pid: %u, mp_parent: %d\n",
                    i, mproc[i].mp_pid, mproc[i].mp_parent);

        pidinfo[i].idx = i;
        pidinfo[i].pid = mproc[i].mp_pid;
        pidinfo[i].parent_idx = mproc[i].mp_parent;
    }
    
    return sys_vircopy(SELF, (vir_bytes) pidinfo, who_e, pidinfo_arr,
                NR_PROCS * sizeof(struct pidinfo));
}