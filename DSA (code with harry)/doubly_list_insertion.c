#include<stdio.h>
#include<STDLIB.H>

struct node
{
    struct node *prev;
    int data;
    struct node *next;

};

void circularListForwardTraversal(struct node *head){
    struct node *ptr=head;
    do
    {
        printf("element is %d \n",ptr->data);
        ptr=ptr->next;
    } while (ptr !=NULL);
    
}


struct node *insertAtFirst(struct node *head , int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    ptr->next=head;
    p->prev=ptr;
    head=ptr;   //ab head ptr ho gya
    // ptr->prev=NULL;    isme null isliye ni dale kyuki yha phle se null rhega prev part m
    
    
    
}

struct node *insertAtLast(struct node *head , int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while (p->next !=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    
    
}


struct node *insertAtIndex(struct node *head , int index ,int data){

  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *p=head;
  
  int i=0;
  while (i!= index-1)
  {
    p=p->next;
    i++;
  }
  ptr->data=data;
  ptr->next=p->next;
  p->next=ptr;
  ptr->prev=p;
  return head;
}



struct node *insertAfterNode(struct node *head , struct node *prevNode ,int data){

  struct node *ptr=(struct node *)malloc(sizeof(struct node));
 
  
  ptr->data=data;
  
  ptr->next=prevNode->next;
  prevNode->next=ptr;
  ptr->prev=prevNode;
  return head;
}





int main(){
struct node *n1=(struct node *)malloc(sizeof(struct node));
struct node *n2=(struct node *)malloc(sizeof(struct node));
struct node *n3=(struct node *)malloc(sizeof(struct node));
struct node *n4=(struct node *)malloc(sizeof(struct node));

n1->next=n2;
n1->prev=NULL;
n1->data=4;

n2->next=n3;
n2->prev=n1;
n2->data=44;

n3->next=n4;
n3->prev=n2;
n3->data=444;

n4->next=NULL; 
n4->prev=n3;
n4->data=4444;

 circularListForwardTraversal(n1);
//  n1=insertAtFirst(n1,3333);
//  n1=insertAtLast(n1,555555);
//  n1=insertAtIndex(n1,3,10234);
n1=insertAfterNode(n1,n3,234);
 circularListForwardTraversal(n1);


return 0 ;
}