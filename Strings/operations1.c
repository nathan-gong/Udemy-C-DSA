#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stringLength(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

// count number of vowels and consonants
void vowCon(char *str)
{
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vowels++;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            consonants++;
        }
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

// count number of words and spaces
void wordSpace(char *str)
{
    int words = 1, spaces = 0;
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (str[i - 1] != ' ' && str[i] == ' ')
        {
            words++;
            spaces++;
        }
        else if (str[i] == ' ')
        {
            spaces++;
        }
    }
    printf("Words: %d\n", words);
    printf("Spaces: %d\n", spaces);
}

// reverse the given string using new array
void reverse(char *str)
{
    int i = stringLength(str) - 1, j;
    char *s = malloc((i + 2) * sizeof(char));
    for (j = 0; i >= 0; i--, j++)
    {
        s[j] = str[i];
    }
    s[j] = '\0';
    printf("Reverse: %s\n", s);
    free(s);
}

// reverse the given string using mutation
void reverse2(char *str)
{
    int n = stringLength(str);
    int t = 0;
    for (int i = 0; i < n / 2; i++)
    {
        t = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = t;
    }
    printf("Reverse: %s\n", str);
}

// compare two given strings
int compareStrings(char *str1, char *str2)
{
    int n = 0;
    if (stringLength(str1) <= stringLength(str2))
    {
        n = stringLength(str1);
    }
    else
    {
        n = stringLength(str2);
    }

    for (int i = 0; i < n; i++)
    {
        if (str1[i] < str2[i])
        {
            return -1;
        }
        else if (str1[i] > str2[i])
        {
            return 1;
        }
    }
    return 0;
}

// check if a string is palindromic
bool palindrome(char *str)
{
    int n = stringLength(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[n - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char *s = "nathan";
    char *s1 = "nathan the   hackerman";
    char *s2 = "nate";

    vowCon(s);
    wordSpace(s1);
    reverse(s);
    // reverse2(s);
    printf("Compare: %d\n", compareStrings(s, s2));
    printf("Compare: %d\n", compareStrings(s, s));
    printf("Compare: %d\n", compareStrings(s2, s));
}