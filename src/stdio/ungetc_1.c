#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = stdin;
    c = fgetc(fp);

    if (c == EOF) {
        perror("fgetc failed");
        // fclose(fp);
        return 1;
    }

    if (ungetc(c, fp) == EOF) {
        perror("ungetc failed");
        // fclose(fp);
        return 1;
    }


    int d;
    while ((d = fgetc(fp)) != EOF)
    {
        if (putchar(d) == EOF)
        {
            perror("putchar");
            // fclose(fp);
            return 1;
        }
    }

    return 0;
}