#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

struct Stack
{
    struct Queue *q1;
    struct Queue *q2;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

void push(struct Stack *stack, int data)
{
    enqueue(stack->q2, data);

    while (!isEmpty(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack->q1))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(stack->q1);
}

int top(struct Stack *stack)
{
    if (isEmpty(stack->q1))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->q1->array[stack->q1->front];
}

int isStackEmpty(struct Stack *stack)
{
    return isEmpty(stack->q1);
}

int main()
{
    struct Stack *stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element is %d\n", top(stack));
    printf("Popped element is %d\n", pop(stack));
    printf("Top element is %d\n", top(stack));

    return 0;
}