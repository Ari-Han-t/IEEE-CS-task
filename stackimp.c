#include <stdio.h>
#define MAX_SIZE 10000

typedef struct
{
    int stack[MAX_SIZE];
    int minStack[MAX_SIZE];
    int maxStack[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s)
{
    s->top = -1;
}
void push(Stack *s, int x)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = x;
    if (s->top == 0 || x < s->minStack[s->top - 1])
        s->minStack[s->top] = x;
    else
        s->minStack[s->top] = s->minStack[s->top - 1];
    if (s->top == 0 || x > s->maxStack[s->top - 1])
        s->maxStack[s->top] = x;
    else
        s->maxStack[s->top] = s->maxStack[s->top - 1];
}
int pop(Stack *s)
{
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->stack[s->top--];
}
int top(Stack *s)
{
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}
int getMin(Stack *s)
{
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->minStack[s->top];
}
int getMax(Stack *s) 
{
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->maxStack[s->top];
}
int main()
{
    Stack stack;
    initStack(&stack);
    int choice, value;
    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Get Max\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = top(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                value = getMin(&stack);
                if (value != -1)
                    printf("Minimum element: %d\n", value);
                break;
            case 5:
                value = getMax(&stack);
                if (value != -1)
                    printf("Maximum element: %d\n", value);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
