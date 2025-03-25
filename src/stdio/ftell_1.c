#include <stdio.h>
#define SEEK_AT 4

int main(void)
{
    int ret;

    FILE *fp = fopen("res/ftell_1-text.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    ret = fseek(fp, SEEK_AT, SEEK_CUR);
    if (ret != 0) {
        perror("fseek");
        fclose(fp);
        return 1;
    }

    ret = ftell(fp);
    if (ret == -1) {
        perror("ftell");
        fclose(fp);
        return 1;
    }

    printf("ftell: %d\n", ret);

    fclose(fp);
    return 0;
}