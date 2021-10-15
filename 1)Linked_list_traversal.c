#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void traversal(struct Node *ptr)
{
     while (ptr!=NULL)
     {
         printf("Element : %d \n", ptr->data);
         ptr= ptr->next;
     }
     
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
    fourth->next=NULL;

    traversal(head);
    return 0;

}
