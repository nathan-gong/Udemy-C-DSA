// Polynomial representation using linked lists

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
{
    struct Node *t, *last = NULL;
    int num, i;

    printf("Enter number of terms:");
    scanf("%d", &num);
    printf("Enter each term (coeff exp):");

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

double eval(struct Node *p, int x)
{
    double val = 0.0;

    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main()
{
    create();
    display(poly);
    printf("%ld\n", eval(poly, 1));
    
    return 0;
}