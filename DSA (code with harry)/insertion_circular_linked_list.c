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


struct Node * insertAtFirst (struct Node *head ,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;

    while (p->next !=head)
    {
        p=p->next;
    }
    //at this point p points to the last node of this circular linked list

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
    
}


struct Node * insertAtGivenIndex(struct Node *head, int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
     struct Node * p=head;
    int i =0;
    while ( i != index-1)
    {
        p= p->next;
        i++;

    }

    ptr->next=p->next;
    p->next=ptr;
    
};


struct Node * insertAtEnd (struct Node*head,int data)
{
   struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
   ptr->data=data;

   struct Node * p=head;
   
   while (p->next != head)
   {
     p=p->next;
   } 

   p->next=ptr;
   ptr->next=head;
   return head;
   
};



struct Node * insertAfterNode(struct Node * head, int data ,struct Node* prevNode)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;

};




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
     third->data=6;
     third->next=fourth;

     //terminatiing the list at the fourth node
     fourth->data=1;
     fourth->next=head;


     printf("circular linked list before insertion \n");
     linkedListTraversal(head); //passing head to function because alll are linked with it

    //  head=insertAtFirst(head,6000);
    //  head =insertAtGivenIndex(head,333,2);
    //  head =insertAfterNode(head,4444,second);
    head = insertAtEnd(head,234564);
     printf("circular linked list after insertion \n");
     linkedListTraversal(head);
 
     
return 0 ;
}