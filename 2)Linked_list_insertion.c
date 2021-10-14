#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE 1 - Insert element at start
struct Node *insertatSTART(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// CASE 2 - Insert at a given index
struct Node *insertatINDEX(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    // int i = 0;
    // while (i != index - 1)
    // {
    //     p = p->next;
    //     i++;
    // }
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// CASE 3 - Insert at end
struct Node *insertatEND(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//  CASE 4 - Insert after a given node

struct Node *insertafterNODE(struct Node *head, struct Node *prevnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 60;
    fourth->next = NULL;

    printf("Linked List before insertion\n");
    traversal(head);
    // head = insertatSTART(head,00);
    // head = insertatINDEX(head,40,3);
    // head = insertatEND(head,70);
    printf("\nLinked List after insertion\n");
    head = insertafterNODE(head, second, 40);
    traversal(head);
    return 0;
}
