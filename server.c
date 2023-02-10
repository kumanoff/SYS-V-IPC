/* Filename: msgq_recv.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "file_handler.h"
#include <string.h>

#define PERMS 0600//0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int main(void) {
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;
    char * fname = "queue.c";
   
    if ((key = ftok(fname, 'B')) == -1) {
       perror("ftok");
       exit(1);
    }
   
    if ((msqid = msgget(key, PERMS)) == -1) { /* connect to the queue */
       perror("msgget\n");
       exit(1);
    }
    printf("message queue: ready to receive messages.\n");
   
        /* this program ends wuth string of end */
    if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
       perror("msgrcv");
       exit(1);
    }
    printf("received: \"%s\"\n", buf.mtext);
    
    text_file(buf.mtext);

    return 0;
}