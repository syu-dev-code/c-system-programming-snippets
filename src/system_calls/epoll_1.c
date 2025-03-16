#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>

int main(void)
{
    struct epoll_event event;
    int epfd;
    int epctl;

    epfd = epoll_create(10);
    if (epfd < 0)
    {
        perror("epoll_create");
        return 1;
    }

    event.events = EPOLLIN | EPOLLOUT;
    event.data.fd = STDIN_FILENO;

    epctl = epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    if (epctl < 0)
    {
        perror("epoll_ctl");
        close(epfd);
        return 1;
    }

    struct epoll_event events[1];  // prepare event array
    int ret = epoll_wait(epfd, events, 1, 5000);
    if (ret < 0)
    {
        perror("epoll_wait");
        close(epfd);
        return 1;
    }
    else if (ret == 0)
    {
        printf("Timeout\n");
    }
    else
    {
        // handle events
        if (events[0].events & EPOLLIN)
        {
            printf("Input event occurred\n");

            char buf[1024];
            int len = read(STDIN_FILENO, buf, sizeof(buf));
            if (len < 0)
            {
                perror("read");
                close(epfd);
                return 1;
            }
            if (len > 0)
            {
                buf[len] = '\0';
                printf("read: %s", buf);
            }
        }
        if (events[0].events & EPOLLOUT)
        {
            printf("Output event occurred\n");
        }
    }

    close(epfd);  // cleanup resources
    return 0;
}