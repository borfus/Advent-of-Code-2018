// Advent of Code 2018
// Day 3 - Part 1

#include <stdio.h>
#include <string.h>

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
    printf("%i\n", square_inches);

    fclose(file);
    return 0;
}
