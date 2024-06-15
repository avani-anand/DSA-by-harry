#include<stdio.h>
#include<stdlib.h>

//making global variable 
struct node * f= NULL;
struct node * r=NULL;

struct node{
    int data;
    struct node * next;
};

void linkedListtraversla(struct node *ptr){
    printf("printing the elements of this linked list \n");
    while (ptr != NULL)
    {
           printf("element : %d\n", ptr->data);
           ptr=ptr->next;
    }
    
}

void enqueue (int val){

 struct node *n=(struct node *)malloc(sizeof(struct node));
 if (n==NULL)
 {
    printf("queue is full \n");
 }
 else
 {
    n->data=val;
    n->next=NULL;
    if (f==NULL)
    {
        f=r=n;
    }
    else
    {
        r->next=n;
        r=n;
    }
    
 }
 
 
}

int dequeue(){
    int val=-1;
    struct node *ptr=f;

    if (f==NULL)
    {
        printf("queue is empty \n");
    }
    else
    {
         f=f->next;
         val = ptr->data;
         free(ptr);
    }
    return val;
    
}

int main(){

linkedListtraversla(f);

printf("dequeue element %d\n", dequeue()); //without putting value in queue trying to dequeue
enqueue(23);
enqueue(1223);
enqueue(6123);
enqueue(03);

printf("dequeue element %d\n", dequeue());
linkedListtraversla(f);


return 0 ;
}