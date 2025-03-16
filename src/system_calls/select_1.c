#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#define TIMEOUT 3
#define BUFFER_LENGTH 1024

int main(void)
{
    struct timeval tv;
    fd_set fds;

    while (1)
    {
        // fd_set must be initialized before each select call
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        // Block until input arrives or timeout
        int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
        if (ret == -1)
        {
            perror("select");
            return 1;
        }

        if (ret == 0)
        {
            fprintf(stdout, "%d seconds elapsed.\n", TIMEOUT);
            continue;
        }

        if (FD_ISSET(STDIN_FILENO, &fds))
        {
            char buf[BUFFER_LENGTH + 1];
            int len = read(STDIN_FILENO, buf, BUFFER_LENGTH);
            if (len == -1)
            {
                perror("read");
                return 1;
            }
            if (len == 0)
            {
                fprintf(stdout, "EOF\n");
                break;
            }
            if (len > 0)
            {
                buf[len] = '\0';
                fprintf(stdout, "read: %s", buf);
            }
        }
    }

    return 0;
}