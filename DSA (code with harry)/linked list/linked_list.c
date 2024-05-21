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
     head->data=7;
     head->next=second;

     //linking second and third nodes
     second->data=17;
     second->next=third;

     //linking third and fourth nodes
     third->data=117;
     third->next=fourth;

     //terminatiing the list at the fourth node
     fourth->data=1117;
     fourth->next=NULL;

     linkedListTraversal(head); //passing head to function because alll are linked with it


return 0 ;
}