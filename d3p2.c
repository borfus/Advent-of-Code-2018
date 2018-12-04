// Advent of Code 2018
// Day 3 - Part 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int fabric_dimensions = 1000, id, left_offset, top_offset, width, height, square_inches = 0;
    char fabric[1000][1000] = { 0 };

    while (fscanf(file, "#%i @ %i,%i: %ix%i\n", &id, &left_offset, &top_offset, &width, &height) != EOF)
    {
        for (int y = top_offset; y < top_offset + height; y++)
        {
            for (int x = left_offset; x < left_offset + width; x++)
            {
                if (fabric[y][x] != 'x' && fabric[y][x])
                {
                    fabric[y][x] = 'x';
                    square_inches++;
                }
                else if (!fabric[y][x])
                {
                    fabric[y][x] = '.';
                }
            }
        }
    }

    rewind(file);
    while (fscanf(file, "#%i @ %i,%i: %ix%i\n", &id, &left_offset, &top_offset, &width, &height) != EOF)
    {
        for (int y = top_offset; y < top_offset + height; y++)
        {
            bool should_break = false;
            for (int x = left_offset; x < left_offset + width; x++)
            {
                if (fabric[y][x] == 'x')
                {
                    should_break = true;
                    break;
                }
                else if (y == (top_offset+height) - 1 && x == (left_offset+width) -1)
                {
                    printf("%i\n", id);
                    exit(0);
                }
            }
            if (should_break)
                break;
        }
    }

    fclose(file);
    return 0;
}
