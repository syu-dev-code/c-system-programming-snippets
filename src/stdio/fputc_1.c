#include <stdio.h>

int main() {
    FILE *fp;
    fp = stdout;

    if (fputc('s', fp) == EOF) {
        perror("fputc");
        return 1;
    }

    if (fputc('\n', fp) == EOF) {
        perror("fputc");
        return 1;
    }

    fclose(fp);
    return 0;
}