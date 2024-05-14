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


struct Node *insertAtFirst (struct Node *head , int data)
{
  struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->next=head;
  ptr->data=data;
  return ptr;
    
};
struct Node *insertAtEnd (struct Node *head , int data)
{
  struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->data=data;

  struct Node * p=head;

  while (p->next !=NULL)
  {
    p=p->next;
  }
  p->next=ptr;
  ptr->next=NULL;
  return head;
    
};


struct Node * insertAtIndex(struct Node *head , int data ,int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i = 0;
     while (i != index-1)
     {
        p = p->next;     //p next next move krte rhega jbtk index na mil jae
        i++;
     }
     ptr->data=data;
     ptr->next=p->next;
     p->next=ptr;   // jha index mil jaega vha ka next p m rhega jisko hum apne ptr m dal denge
     return head; //head change ni hoga vhi rhega
}

struct Node *insertAfterNode (struct Node *head , struct Node *prevNode ,int data)
{
  struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
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

     printf("linked list before insertion\n");
     linkedListTraversal(head); //passing head to function because alll are linked with it
    //  head=insertAtFirst(head,56);
    //  head=insertAtIndex(head,56,1);
    //  head=insertAtEnd(head,56);
     head=insertAfterNode(head,second,455);  //giving second node to insert after second

     printf("linked list after insertion\n");
     linkedListTraversal(head);

return 0 ;
}