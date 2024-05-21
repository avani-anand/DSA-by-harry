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


//case 2: dleleting at any given index
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p=head; //pointing p to head(first)
    struct Node *q=head->next;     //pointing q to next of p


// running the loop till p is before q. and q is at desire index we want to delete 
    for (int i = 0; i < index-1; i++)
    {
     p=p->next;
     q=p->next;   
    }

    //after looping when p and q at desire position

    p->next=q->next;   //putting q next to p then q is unlinked and we will be free it
    free(q); //delete q
    return(head);
    
}


// case 3: delete at last
struct Node *deleteAtLast(struct Node * head){
    struct Node *p= head;
    struct Node *q=head->next;

// running the loop till p is before q. and q next is NULL 

    while (q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}




//case 4: dleleting given value
            //THEY DON'T WORK ON FIRST NODE DATA
   struct Node * deleteGivenvalue(struct Node * head , int value){
    struct Node *p=head; //pointing p to head(first)
    struct Node *q=head->next;     //pointing q to next of p


// running the loop till q data== given value and if value not found so q-> != NULL  
    while (q->data != value && q->next !=NULL)
    {
       p=p->next;
        q=p->next;  
    }

    //after looping when p and q at desire position

     if (q->data == value)
     {
       p->next=q->next;
       free(q);
        
     }else{
        printf("daata is not found ! \n");
     }

     
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

      
    //  head =deleteFirst(head);  //for deleting first element
    head=deleteAtIndex(head,2);      //deleting 2nd index
    // head=deleteAtLast(head);
    // head=deleteGivenvalue(head, 3);
 
     printf("linked list after deletion \n");   
     linkedListTraversal(head); 

return 0 ;
}