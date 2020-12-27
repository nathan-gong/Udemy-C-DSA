#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size:");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack underflow");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid index");
    x = st.S[st.top - index + 1];

    return x;
}

bool isEmpty(struct Stack st)
{
    return st.top == -1;
}

bool isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("%d \n", peek(st, 2));

    display(st);

    return 0;
}