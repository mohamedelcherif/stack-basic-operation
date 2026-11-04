
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

void initstack(stack *s)
{
    s->top = NULL;
}

int isEmpty(stack *s)
{
    return s->top == NULL;
}

void push(stack *s, int d)
{
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL)
        return;

    newnode->data = d;
    newnode->next = s->top;

    s->top = newnode;
}

int pop(stack *s)
{
    if (isEmpty(s))
        return -1;

    node *temp = s->top;
    int d = temp->data;

    s->top = s->top->next;

    free(temp);

    return d;
}

int peek(stack *s)
{
    if (isEmpty(s))
        return -1;

    return s->top->data;
}

int main()
{
    stack s;

    initstack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", peek(&s));
    printf("Pop: %d\n", pop(&s));
    printf("New top: %d\n", peek(&s));

    return 0;
}
