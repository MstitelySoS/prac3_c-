/* ----------------------------------------------------
 * NAME: Абармов А.С.  GROUP: КВБО-07-23
 * FILE: prog1.c
 * PURPOSE: Родительский процесс: fork + exec + wait
 * ---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static void on_sigint(int signo) {
    (void)signo;
    write(STDOUT_FILENO, "\n[prog1] Caught SIGINT, exiting...\n", 34);
    _exit(0);
}

int main(void) {
    signal(SIGINT, on_sigint); /* упрощённый handler для демонстрации */

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        /* child заменяет себя на ./process */
        execl("./process", "process", (char*)NULL);
        perror("execl failed");
        _exit(127);
    } else {
        printf("[prog1] parent pid=%d, child pid=%d — waiting...\n",
               (int)getpid(), (int)pid);
        int status = 0;
        if (waitpid(pid, &status, 0) < 0) {
            perror("waitpid failed");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("[prog1] child exited with code %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("[prog1] child killed by signal %d\n", WTERMSIG(status));
        }
        printf("[prog1] done.\n");
        return 0;
    }
}
