#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void traversal(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr->next!=NULL)
    {
     printf("ELEMENTS : %d \n", ptr->data);
     ptr = ptr->next;
    }
    // printf("ELEMENTS : %d \n", ptr->data);
    while (ptr!=NULL)
    {
        printf("ELEMENTS : %d \n", ptr->data);
        ptr=ptr->prev;
    }
    
}

// void reversal(struct Node* )
// {
//     struct Node* ptr = fourth;
//     while (ptr->prev!= head)
//     {
//         printf("ELEMENTS : %d \n", ptr->data);
//         ptr=ptr->prev;
//     }
    
// }

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
 


   head->prev = NULL;
   head->next = first;
   head->data = 10;
   
   first->prev = head;
   first->next = second;
   first->data = 20;
   
   second->prev = first;
   second->next = third;
   second->data = 30;
   
   third->prev = second;
   third->next = fourth;
   third->data = 40;
   
   fourth->prev = third;
   fourth->next = NULL;
   fourth->data = 50;

   printf("The list is \n");
   traversal(head);
   return 0;
//    printf("Reverse list is \n");
//    reversal(fourth);
  
}