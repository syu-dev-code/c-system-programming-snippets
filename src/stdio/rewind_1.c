#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    const char *filename = "res/rewind_1-text.txt";
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Could not open file '%s': %s\n",
                filename, strerror(errno));
        return 1;
    }

    printf("First read:\n");

    char ch;
    int read_count = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ferror(fp))
        {
            fprintf(stderr, "Error: Failed to read from file: %s\n",
                    strerror(errno));
            fclose(fp);
            return 1;
        }
        read_count++;
    }
    printf("Characters read: %d\n\n", read_count);

    // Reset errno to 0 before calling rewind to detect errors
    errno = 0;

    // Call rewind function
    rewind(fp);

    // Check errno after rewind
    if (errno != 0)
    {
        fprintf(stderr, "Error: Failed to rewind file pointer: %s\n",
                strerror(errno));
        fclose(fp);
        return 1;
    }

    printf("Second read after rewind:\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ferror(fp))
        {
            fprintf(stderr, "Error: Failed to read from file: %s\n",
                    strerror(errno));
            fclose(fp);
            return 1;
        }
        putchar(ch);
    }
    printf("\n");

    fclose(fp);
    return 0;
}