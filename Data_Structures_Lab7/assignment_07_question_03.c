#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

int areStacksIdentical(struct Stack *stack1, struct Stack *stack2)
{
    if (stack1->top != stack2->top)
    {
        return 0;
    }

    for (int i = 0; i <= stack1->top; i++)
    {
        if (stack1->array[i] != stack2->array[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    struct Stack *stack1 = createStack(100);
    struct Stack *stack2 = createStack(100);

    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);

    push(stack2, 10);
    push(stack2, 20);
    push(stack2, 30);

    // Check if the stacks are identical
    if (areStacksIdentical(stack1, stack2))
    {
        printf("The stacks are identical.\n");
    }
    else
    {
        printf("The stacks are not identical.\n");
    }

    free(stack1->array);
    free(stack2->array);
    free(stack1);
    free(stack2);

    return 0;
}