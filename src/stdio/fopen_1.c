#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("res/fopen_1-text.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 1;
    }

    // display the file contents
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (putchar(ch) == EOF)
        {
            perror("putchar");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}