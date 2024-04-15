#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    
    // FIFO file path
    char * myfifo = "/tmp/myfifo1";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
 
    char arr2[80] = "2";
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
 
        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
        usleep(1000000);
    }
    return 0;

    
}