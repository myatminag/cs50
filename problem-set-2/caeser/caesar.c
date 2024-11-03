#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);

    // Prompt user for plaintext
    string plain_text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int n = strlen(plain_text);

    // For each character in the plaintext:
    for (int i = 0; i < n; i++)
    {
        if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
        {
            printf("%c", ((((plain_text[i] - 'a') + k) % 26) + 'a'));
        }
        else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
        {
            printf("%c", ((((plain_text[i] - 'A') + k) % 26) + 'A'));
        }
        else
        {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
    return 0;
}
