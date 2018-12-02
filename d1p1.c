// Advent of Code 2018
// Day 1 - Part 1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int frequency = 0, current_num;
    char symbol;

    while (fscanf(file, "%c%i\n", &symbol, &current_num) != EOF)
    {
        if (symbol == '-')
            frequency -= current_num;
        else
            frequency += current_num;
    }
    printf("%i\n", frequency);

    return 0;
}
