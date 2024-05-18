#include<stdio.h>
#include<stdlib.H>


struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal (struct Node *head){
 struct Node *ptr=head;
  
    do
    {
         printf("element is %d\n", ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    

}

struct Node * deleteFirst(struct Node * head){
    struct Node *ptr=head;
    struct Node *p;
    while (ptr->next!=head)
    {
        ptr=ptr->next;
    }
    p=head;
    head=head->next;
    ptr->next=head;
    
    free(p);
    return head;
}



int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

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
     third->data=6;
     third->next=fourth;

     //terminatiing the list at the fourth node
     fourth->data=1;
     fourth->next=head;

     printf("list before deletion \n");
     linkedListTraversal(head); //passing head to function because alll are linked with it

     printf("list after deletion \n");
     head =deleteFirst(head);
    // head=deleteAtIndex(head,2);
      linkedListTraversal(head);
return 0 ;
}