#include <stdio.h>
#define SEEK_AT 5

int main(void)
{
    int ret;
    fpos_t pos;
    FILE *fp;
    
    fp = fopen("res/fgetpos_1-text.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    ret = fseek(fp, SEEK_AT, SEEK_SET);
    if (ret == -1) {
        perror("fseek");
        fclose(fp);
        return 1;
    }

    ret = fgetpos(fp, &pos);
    if (ret == -1) {
        perror("fgetpos");
        fclose(fp);
        return 1;
    }

    // display fpos_t as bytes
    unsigned char *bytes = (unsigned char *)&pos;
    printf("pos bytes: ");
    for (size_t i = 0; i < sizeof(fpos_t); i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");

    fclose(fp);
    return 0;
}