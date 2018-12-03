// Advent of Code 2018
// Day 2 - Part 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int two_count = 0, three_count = 0;
    char line[32];

    while (fscanf(file, "%s\n", line) != EOF)
    {
        bool two = false, three = false;
        for (int i = 0; i < strlen(line); i++)
        {
            int count = 1;

            for (int j = 0; j < strlen(line); j++)
            {
                if (i == j)
                    continue;

                if (line[i] == line[j])
                    count++;
            }

            if (count == 2 && !two)
            {
                two_count++;
                two = true;
            }
            else if (count == 3 && !three)
            {
                three_count++;
                three = true;
            }

            if (two && three)
                break;
        }
    } 

    printf("%i\n", two_count*three_count);
    return 0;
}
