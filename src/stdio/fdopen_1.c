#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    FILE *fp;
    int fd;

    fd = open("res/fdopen_1-text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    fp = fdopen(fd, "r");
    if (fp == NULL)
    {
        perror("fdopen");
        close(fd);  // Need to close fd if fdopen fails
        return 1;
    }

    // display the file contents
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (putchar(ch) == EOF)
        {
            perror("putchar");
            fclose(fp);  // This will close both fp and fd
            return 1;
        }
    }

    // fclose will also close the underlying file descriptor
    fclose(fp);

    return 0;
}