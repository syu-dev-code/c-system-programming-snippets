#include <stdio.h>

int main(void)
{
    char str[100];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input\n");
        return 1;
    }
    printf("input: %s\n", str);
    return 0;
}