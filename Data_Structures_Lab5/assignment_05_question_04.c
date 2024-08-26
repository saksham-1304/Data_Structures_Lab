// To Print The Values At Even And Odd Nodes Of A Linked List Seperately

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printOdd(struct Node *head)
{
    int i = 1;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (i % 2 != 0)
        {
            printf("%d ", curr->data);
        }
        i++;
        curr = curr->next;
    }
}
void printEven(struct Node *head)
{
    int i = 1;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (i % 2 == 0)
        {
            printf("%d ", curr->data);
        }
        i++;
        curr = curr->next;
    }
}

int main()
{
    struct Node *head = createNode(14);
    head->next = createNode(27);
    head->next->next = createNode(23);
    head->next->next->next = createNode(42);
    head->next->next->next->next = createNode(15);
    printf("Value at Odd Nodes : ");
    printOdd(head);
    printf("\n");
    printf("Value at Even Nodes: ");
    printEven(head);
    printf("\n");
}
