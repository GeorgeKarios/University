// Karyos Georgios 30738 - Stylianos Farmakas 30833
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void create_tree(int i, int N) {
    pid_t left = -1, right = -1;
    //aristero 
    if (2*i <= N) {
        left = fork();
        if (left == 0) {
            create_tree(2*i, N);
            exit(0);
        }
    }

    //dexio
    if (2*i + 1 <= N) {
        right = fork();
        if (right == 0) {
            create_tree(2*i + 1, N);
            exit(0);
        }
    }

    if (left > 0)
        wait(NULL);
    if (right > 0)
        wait(NULL);

    // print 3 fores
    for (int t = 0; t < 3; t++) {
        printf("MyPID=%d ", getpid());
        printf("ParentPID=%d ", getppid());
        printf("Position=%d ", i);
        if (left > 0)
            printf("LeftChildPID=%d LeftPos=%d ", left, 2*i);
        else
            printf("LeftChild=NULL ");
        if (right > 0)
            printf("RightChildPID=%d RightPos=%d ", right, 2*i+1);
        else
            printf("RightChild=NULL ");
        if (i == 1)
            printf("ParentPos=NULL");
        else
            printf("ParentPos=%d", i/2);
        printf("\n");
        sleep(1);
    }
}

int main() {
    int N;
    printf("Give number of processes: ");
    scanf("%d", &N);
    if (N < 1) {
        printf("N must be >= 1\n");
        return 1;
    }
    create_tree(1, N);
    return 0;
}