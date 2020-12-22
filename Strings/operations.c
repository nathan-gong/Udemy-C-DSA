#include <stdio.h>
#include <stdlib.h>

// length of a string
int stringLength(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len += 1;
    }
    return len;
}

// from lowercase to uppercase
void lowerToUpper(char *str)
{
    char *s = malloc(stringLength(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        s[i] = str[i] - 32;
    }
    printf("%s\n", s);
    free(s);
}

// from uppercase to lowercase
void upperToLower(char *str)
{
    char *s = malloc(stringLength(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        s[i] = str[i] + 32;
    }
    printf("%s\n", s);
    free(s);
}

// all to uppercase
void toUpper(char *str)
{
    char *s = malloc(stringLength(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        // if lower
        if (str[i] >= 97 && str[i] <= 122)
        {
            s[i] = str[i] - 32;
        }
        else
        {
            s[i] = str[i];
        }
    }
    printf("%s\n", s);
    free(s);
}

// all to lowercase
void toLower(char *str)
{
    char *s = malloc(stringLength(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        // if lower
        if (str[i] >= 65 && str[i] <= 90)
        {
            s[i] = str[i] + 32;
        }
        else
        {
            s[i] = str[i];
        }
    }
    printf("%s\n", s);
    free(s);
}

// switch cases
void switchCase(char *str)
{
    char *s = malloc(stringLength(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            s[i] = str[i] + 32;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            s[i] = str[i] - 32;
        }
    }
    printf("%s\n", s);
    free(s);
}

int main()
{
    char *s = "nathan";
    char *s1 = "NATHAN";
    char *s2 = "NatHan";
    printf("%s\n", s);

    printf("Length: %d\n", stringLength(s));
    lowerToUpper(s);
    upperToLower(s1);
    toUpper(s2);
    toLower(s2);
    switchCase(s2);
}