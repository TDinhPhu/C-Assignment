#include <stdio.h>

void capitalizeAfterDot(char *str)
{
    int capitalize = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            capitalize = 1;
        }
        else if (capitalize)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
    }
}

int main()
{
    char input[1000];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    capitalizeAfterDot(input);
    printf("Result: %s\n", input);

    return 0;
}