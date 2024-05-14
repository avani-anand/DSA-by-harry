#include<stdio.h>
#include<stdlib.H>


struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal (struct Node *ptr){
    while (ptr !=NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }
    
}


//case 1: deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node *ptr=head; // pointing ptr same to where is head
    head=head->next;    // puting head"s  next in head
    free(ptr); //now ptr is still there on first where head was so delelting this memory
    return head;
}


int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

//allocating memory for nodes in the linked list in heap
// we have to give every node a new memory because they are not contigous to memory
     head=(struct Node *)malloc (sizeof(struct Node)); //giving memory to head node 
     second=(struct Node *)malloc (sizeof(struct Node)); //giving memory to second node
     third=(struct Node *)malloc (sizeof(struct Node)); //giving memory to third node
     fourth=(struct Node *)malloc (sizeof(struct Node)); //giving memory to fourth node


     //linking first(head) and second nodes
     head->data=4;
     head->next=second;

     //linking second and third nodes
     second->data=3;
     second->next=third;

     //linking third and fourth nodes
     third->data=8;
     third->next=fourth;

     //terminatiing the list at the fourth node
     fourth->data=1;
     fourth->next=NULL;
        
     printf("linked list before deletion \n");    
     linkedListTraversal(head); //passing head to function because alll are linked with it

      
     head =deleteFirst(head); 
     head =deleteFirst(head); 
     printf("linked list after deletion \n");   
     linkedListTraversal(head); 

return 0 ;
}