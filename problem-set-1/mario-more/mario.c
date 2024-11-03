#include <cs50.h>
#include <stdio.h>

void print_hashes(int i);

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i) - 1; j++)
        {
            printf(" ");
        }

        print_hashes(i);

        printf("  ");

        print_hashes(i);

        printf("\n");
    }
}

void print_hashes(int i)
{
    for (int l = 0; l <= i; l++)
    {
        printf("#");
    }
}
