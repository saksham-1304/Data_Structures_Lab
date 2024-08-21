// To Find The Middle Element Of A Linked List
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
void findMiddle(struct Node *head)
{
    struct Node *slowPtr = head;
    struct Node *fastPtr = head;
    if (head != NULL)
    {
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        printf("The middle element is : %d\n", slowPtr->data);
    }
}

int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    findMiddle(head);
    return 0;
}
