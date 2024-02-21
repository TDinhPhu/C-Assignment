#include <stdio.h>
#include <string.h>

int findText(const char *string, const char *subString)
{
    int stringLen = 0;
    int subStringLen = 0;
    while (string[stringLen] != '\0')
    {
        stringLen++;
    }
    while (subString[subStringLen] != '\0')
    {
        subStringLen++;
    }

    for (int i = 0; i <= stringLen; i++) // 0 24    0 1 2 3 4
    {
        int j;
        for ( j = 0; j < subStringLen; j++) // on 0 2   0 1 
        {
            if (string[i+j] != subString[j])
            {
                break; 
            }
        }
        if (j == subStringLen)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char string[] = "Xin cam on tat ca moi nguoi";
    char subString[100];

    printf("Enter string want to find: ");
    fgets(subString, sizeof(subString), stdin);
    subString[strcspn(subString, "\n")] = '\0'; //remove space

    int position = findText(string, subString);

    if (position != -1)
    {
        printf("Substring '%s' founded.\n", subString);
        printf("Position: %d\n", position);
    }
    else
    {
        printf("Substring '%s' can not find.\n", subString);
    }

    return 0;
}
