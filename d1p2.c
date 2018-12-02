// Advent of Code 2018
// Day 1 - Part 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int frequency = 0, current_num, frequencies[262144], i = 1;
    char symbol;
    bool answered = false;

    frequencies[0] = 0;
    while (!answered)
    {
        rewind(file);
        for (; fscanf(file, "%c%i\n", &symbol, &current_num) != EOF && !answered; i++)
        {
            if (symbol == '-')
                frequency -= current_num;
            else
                frequency += current_num;

            frequencies[i] = frequency;
            for (int j = 0; j <= i; j++)
            {
                if (j == i)
                    continue;

                if (frequencies[j] == frequency)
                {
                    answered = true;
                    printf("%i\n", frequency);
                    break;
                }
            }
        }
    }

    fclose(file);
    return 0;
}
