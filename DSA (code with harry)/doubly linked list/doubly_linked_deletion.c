#include<stdio.h>
#include<STDLIB.H>

struct node
{
    struct node *prev;
    int data;
    struct node *next;

};

void traversal(struct node *head){
    struct node *ptr=head;
    do
    {
        printf("element is %d \n",ptr->data);
        ptr=ptr->next;
    } while (ptr !=NULL);
    
}


struct node * deleteAtFirst(struct node * head){
    struct node *ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}

struct node * deleteAtIndex(struct node *head , int index){
    struct node *p=head;
    struct node *q=head->next;
    struct node *c=q->next;

    for (int i=0; i<index-1;i++)
    {
       p=p->next;
       q=p->next;
       c=q->next;
    }
    
    p->next=q->next;
    c=p;
    free(q);
    return(head);

}

// case 3: delete at last
struct node *deleteAtLast(struct node * head){
   struct node *p=head;
   struct node * q=head->next;
   while (q->next !=NULL)
   {
     q=q->next;
     p=p->next;
   }
   p->next=NULL;
   free(q);
   return(head);

}

//case 4: dleleting given value
            //THEY DON'T WORK ON FIRST NODE DATA
struct node *deleteGivenValue(struct node * head, int value){
    struct node *p=head;
    struct node *q=head->next;
    struct node *c=q->next;

    while (q->data !=value && q->next != NULL)
    {
       p=p->next;
       q=p->next;
       c=q->next;
    }
    if (q->data ==value)
    {
        p->next=q->next;
        c=p;
        free(q);

    }else
    {
        printf("value is not found \n");
    }
    
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

 traversal(n1);
//  n1=deleteAtFirst(n1);
//  n1=deleteAtIndex(n1,2);
//  n1=deleteAtLast(n1);
n1=deleteGivenValue(n1,44);
 printf("after deletion \n");
 traversal(n1);
return 0 ;
}