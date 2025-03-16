#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("res/fgetc_1-text.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 1;
    }

    int c;

    c = fgetc(fp);

    if (c == EOF)
    {
        perror("fgetc");
        fclose(fp);
        return 1;
    }

    printf("%c\n", c);

    fclose(fp);

    return 0;
}