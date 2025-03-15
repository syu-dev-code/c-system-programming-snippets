#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
void sig_handler(int sig);

int received_sig = 0;

int main(void)
{
    signal(SIGTERM, sig_handler);
    signal(SIGINT, sig_handler);
    while (1)
    {
        fprintf(stdout, "waiting...\n");
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        select(0, NULL, NULL, NULL, &tv);

        if (received_sig > 0)
        {
            fprintf(stdout, "SIGTERM received %d\n", received_sig);
            return 0;
        }
    }
}

void sig_handler(int sig)
{
    received_sig = sig;
}