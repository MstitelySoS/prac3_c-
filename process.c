/* ----------------------------------------------------
 * NAME: Абрамов А.С.  GROUP: КВБО-07-23
 * FILE: process.c
 * PURPOSE: Дочерний процесс: цикл с выводом
 * ---------------------------------------------------- */
#include <stdio.h>
#include <unistd.h>

#define MAX_COUNT 200

int main(void) {
    for (int i = 1; i <= MAX_COUNT; ++i) {
        printf("[process] iteration %d (pid=%d)\n", i, (int)getpid());
        if ((i % 25) == 0) usleep(5000);
    }
    printf("[process] finished (pid=%d)\n", (int)getpid());
    return 0;
}
