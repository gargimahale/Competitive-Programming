#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

// int main(int argc, char *argv[]){
//     // printf("Hello World (pid: %d)\n", (int) getpid());
//     int rc = fork();
//     if (rc < 0){
//         fprintf(stderr, "Fork Failed!\n");
//         exit(1);
//     }else if (rc == 0){
//         close(STDOUT_FILENO);
//         open("p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

//         // printf("Hello, I'm child (pid: %d)\n", (int) getpid());
//         char *myargs[3];
//         myargs[0] = strdup("wc");
//         myargs[1] = strdup("mem.c");
//         myargs[2] = NULL;
//         execvp(myargs[0], myargs);
//         // printf("This should not be printed\n");
//     }
//     else {
//         int wc = wait(NULL);
//         // printf("Hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
//     }
//     return 0;
// }



int main(int argc, char *argv[]){   
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "FOrk Failed\n");
        exit(1);
    }
    else if (rc == 0){
        close(STDOUT_FILENO);
        open("p4.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("IO.c");
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
    }
    else{
        int wc = wait(NULL);
    }
    return 0;
}