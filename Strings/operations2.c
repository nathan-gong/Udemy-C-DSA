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

// find duplicate chars in a string
void duplicates(char *str)
{
    char *s = malloc(26 * sizeof(char));
    for (int i = 0; i < 26; i++)
    {
        s[i] = 0;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        s[str[i] - 97] += 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (s[i] > 1)
        {
            printf("%d %c\n", s[i], i + 97);
        }
    }
}

// find duplicate chars in a string using bitwise operations
void duplicates2(char *str)
{
    int h = 0, x = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << (str[i] - 97);
        if ((x & h) > 0)
            printf("%c is duplicate\n", str[i]);
        else
            h = x | h;
    }
}

// check if two strings are anagrams
bool anagram(char *str1, char *str2) {
    char *s = malloc(26 * sizeof(char));
    for (int i = 0; i < 26; i++)
    {
        s[i] = 0;
    }
    for (int i = 0; str1[i] != '\0'; i++)
    {
        s[str1[i] - 97] += 1;
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        s[str2[i] - 97] -= 1;
        if (s[str1[i] - 97] < 0) {
            return false;
        }
    }
    return true;
}

// display array
void printArray(char arr[], int n) {
    for (int i = 0; i<n; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

// permutations of a string
void perm(char *str, int k) {
    static int a[10] = {0};
    static char res[10];

    if(str[k] == '\0') {
        res[k] = '\0';
        printArray(res, 10);
    }
    else {
        for (int i =0; str[i] != '\0'; i++) {
            if (a[i] == 0) {
                res[k] = str[i];
                a[i] = 1;
                perm(str, k+1);
                a[i] = 0;
            }
        }
    }
}

int main()
{
    char *s = "nathan";
    char *s1 = "decimal";
    char *s2 = "medical";
    char *s3 = "abc";

    duplicates(s);
    duplicates2(s);
    printf("%d\n", anagram(s1, s2));
    perm(s3, 0);
}