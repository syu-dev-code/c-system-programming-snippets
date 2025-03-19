#include <stdio.h>

#define BUFFER_SIZE 5

int main(void)
{
    // 'A', 'B', 'C', 'D', 'E' in ASCII
    unsigned char buffer[BUFFER_SIZE] = {65, 66, 67, 68, 69};
    
    FILE *fp = fopen("binary.dat", "wb+");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    
    size_t ret = fwrite(buffer, sizeof(unsigned char), BUFFER_SIZE, fp);
    if (ret < BUFFER_SIZE)
    {
        perror("fwrite");
        fclose(fp);
        return 1;
    }

    unsigned char read_buffer[BUFFER_SIZE];
    fseek(fp, 0, SEEK_SET);
    ret = fread(read_buffer, sizeof(unsigned char), BUFFER_SIZE, fp);
    if (ret < BUFFER_SIZE && ferror(fp))
    {
        perror("fread");
        fclose(fp);
        return 1;
    }

    for (size_t i = 0; i < ret; i++)
    {
        printf("%d(%c) ", read_buffer[i], read_buffer[i]);
    }
    printf("\n");

    fclose(fp);
    return 0;
}
