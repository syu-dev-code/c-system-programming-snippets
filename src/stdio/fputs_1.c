#include <stdio.h>

int main() {
    FILE *fp;
    fp = stdout;

    if (fputs("Hello, World!\n", fp) == EOF) {
        perror("fputs");
        return 1;
    }

    fclose(fp);
    return 0;
}
