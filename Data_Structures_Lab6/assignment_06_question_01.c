#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5
struct GrowableStack
{
  int *array;
  int top;
  int capacity;
};

void initialize(struct GrowableStack *stack)
{
  stack->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
  stack->top = -1;
  stack->capacity = INITIAL_CAPACITY;
}

int isEmpty(struct GrowableStack *stack)
{
  return stack->top == -1;
}

void push(struct GrowableStack *stack, int data)
{
  if (stack->top == stack->capacity - 1)
  {
    // If the stack is full, double the capacity
    stack->capacity *= 2;
    stack->array = (int *)realloc(stack->array, stack->capacity * sizeof(int));
  }
  stack->array[++stack->top] = data;
}

int pop(struct GrowableStack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack->array[stack->top--];
}

int main()
{
  struct GrowableStack stack;
  initialize(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Popped: %d\n", pop(&stack));
  printf("Popped: %d\n", pop(&stack));
  printf("Popped: %d\n", pop(&stack));

  push(&stack, 40);
  push(&stack, 50);

  printf("Popped: %d\n", pop(&stack));
  printf("Popped: %d\n", pop(&stack));

  return 0;
}
