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

void circularListBackwardTraversal(struct node *head){
     struct node *ptr=head;
    do
    {
        printf("element is %d \n",ptr->data);
        ptr=ptr->prev;
    } while (ptr !=NULL);
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
 circularListBackwardTraversal(n4);

return 0 ;
}