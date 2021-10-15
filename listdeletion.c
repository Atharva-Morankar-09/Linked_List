#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void traversal(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("ELEMENT : %d \n", ptr->data);
        ptr=ptr->next;
    }
}

// Case 1 : Deletion of first node

struct Node* deleteatFIRST(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2 : Deletion at a given index

struct Node* deleteatINDEX(struct Node* head,int index)
{
    struct Node* p = head;
    struct Node* q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3 : Deletion at the end

struct Node* deleteatEND(struct Node* head)
{
   struct Node* p = head; 
   struct Node* q = head->next; 

   while(q->next!=NULL)
   {
       p = p->next;
       q = q->next;
   }
   
   p->next = NULL;
   free(q);
   return head;

}

// Case 4 : Deletion with a given value(data)

struct Node* deletewithVALUE(struct Node* head,int value)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if (q->data==value)
    {
        p->next = q->next;
        free(q);
    }
    

    return head;
}

int main()
{
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = NULL;

    printf("Linked List before deletion\n");
    traversal(head);
    
    printf("Linked List after deletion\n");
    // head = deleteatFIRST(head);
    // head = deleteatINDEX(head,2);
    // head = deleteatEND(head);
    head = deletewithVALUE(head,30);
    traversal(head);

    return 0;

}

