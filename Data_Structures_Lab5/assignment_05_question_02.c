//Find A Length Of A Linked List And Reverse It

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
    }
    else
    {
        reverse(curr->next);
        printf("%d ", curr->data);
    }
}

int count(struct Node *head)
{
    struct Node *curr = head;
    if (curr == NULL)
    {
        return 0;
    }
    return 1 + count(curr->next);
}
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

        current = next;
    }
    return prev;
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
    printf("Length of Linked List is  %d\n", count(head));
    // head=reverseList(head);
    printf("Reversed Linked List: ");
    reverse(head);
    printf("\n");
    // printList(head);
    return 0;
}
