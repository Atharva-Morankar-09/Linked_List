#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void traversal(struct Node* head)
{
    struct Node* ptr = head;
    do
    {
        printf("Elements : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    
}

struct Node* replacehead(struct Node* head,int data)
{   
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node* p = head -> next;
    while (p->next!=head)
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next=head;
    head = ptr;
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

    head->data=10;
    head->next=first;

    first->data=20;
    first->next=second;

    second->data=30;
    second->next=third;

    third->data=40;
    third->next=fourth;

    fourth->data=50;
    fourth->next=head;

    printf("Linked list before insertion \n");
    traversal(head);
    head = replacehead(head,00);
    printf("Linked list after insertion \n");
    traversal(head);
    return 0;


}
