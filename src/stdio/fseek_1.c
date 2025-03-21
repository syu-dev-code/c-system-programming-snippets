#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("res/fseek_1-text.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    if (fseek(fp, 5, SEEK_SET) != 0) {
        perror("fseek");
        fclose(fp);
        return 1;
    }
    
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        if (ferror(fp)) {
            perror("fgets");
            fclose(fp);
            return 1;
        } else {
            printf("EOF\n");
            fclose(fp);
            return 0;
        }
    } 

    printf("fgets: %s\n", buffer);
    fclose(fp);
    return 0;
}