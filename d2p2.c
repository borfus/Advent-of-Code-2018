// Advent of Code 2018
// Day 2 - Part 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int line_num = 0;
    char line[32], lines[256][32];

    while (fscanf(file, "%s\n", line) != EOF)
    {
        strcpy(lines[line_num++], line);
    } 
    fclose(file);

    for (int i = 0; i < line_num; i++)
    {
        for (int j = 0; j < line_num; j++)
        {
            int count = 0;
            if (i == j)
                continue;

            for (int k = 0; k < strlen(lines[i]); k++)
            {
                if (lines[i][k] != lines[j][k])
                    count++;

                if (count > 1)
                    break;
            }
            if (count == 1)
            {
                printf("%s\n%s\n", lines[i], lines[j]);
                exit(0);
            }
        }
    }

    return 0;
}
