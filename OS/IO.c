#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

    int fd = open("./file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);
    int rc = write(fd, "Hello World!", 13);
    assert(rc == 13);
    close(fd);

    // OR
    // FILE *fptr = fopen("file.txt", "a");
    // fprintf(fptr, "%s", "Hello World!, My Friend!");
    // fclose(fptr);
    return 0;
}