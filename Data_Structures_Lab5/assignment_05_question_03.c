// Reverse A Linked List

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

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse(struct Node *head)
{
    struct Node *curr = head;
    if (curr == NULL)
    {
        return ;
    }
    else
    {
        reverse(curr->next);
        printf("%d ", curr->data);
    }
}

int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(head);
    printf("Reversed Linked List: ");
    reverse(head);
    printf("\n");

    return 0;
}
