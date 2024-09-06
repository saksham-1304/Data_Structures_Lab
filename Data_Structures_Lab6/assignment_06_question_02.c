#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *link;
};
struct Stack
{
  struct Node *top;
};
struct Node *newNode(int data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));

  if (!node)
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  node->data = data;
  node->link = NULL;
  return node;
}
void initializeStack(struct Stack *stack)
{
  stack->top = NULL;
}
int isEmpty(struct Stack *stack)
{
  return stack->top == NULL;
}
void push(struct Stack *stack, int data)
{
  struct Node *node = newNode(data);
  node->link = stack->top;
  stack->top = node;
}

int peek(struct Stack *stack)
{
  if (!isEmpty(stack))
  {
    return stack->top->data;
  }
  else
  {
    exit(1);
  }
}

void pop(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  else
  {
    struct Node *temp = stack->top;
    stack->top = stack->top->link;
    free(temp);
  }
}
void display(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  else
  {
    struct Node *temp = stack->top;
    while (temp != NULL)
    {
      printf("%d", temp->data);
      temp = temp->link;
      if (temp != NULL)
      {
        printf("-> ");
      }
    }
  }
}
int main()
{
  struct Stack s;
  initializeStack(&s);
  push(&s, 11);
  push(&s, 22);
  push(&s, 33);
  push(&s, 44);
  display(&s);
  printf("\nTop element is %d\n", peek(&s));
  pop(&s);
  pop(&s);
  display(&s);
  printf("\nTop element is %d\n", peek(&s));
  return 0;
}
