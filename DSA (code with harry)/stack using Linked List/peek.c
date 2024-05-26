// another program by making   " struct node* top= NULL;"  as a global variable
#include<STDIO.H>
#include<STDLIB.H>


struct node
{
    int data;
    struct node * next;
};

struct node* top= NULL;
void linkedListTraversal (struct node *ptr){
    while (ptr !=NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }
    
}

int isEmpty(struct node *top){
    if (top== NULL)
    {
     return 1;
    }
    return 0;
}


int isFull(struct node* top){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {
        return 1;
    }
    return 0;
}


int stackTop(struct node * top){
    return top->data;
}

int stackBottom(struct node * top){
    struct node *ptr=top;
    while (ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}

struct node *push(struct node* top, int x){
    if (isFull(top))
    {
     printf("stack overflow \n");
    }else
    {
        struct node*n=(struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;

    }
    
    
}



int pop(struct node* tp){          // ab yha top jo h global variable h to local variable m top ko dusra name dena padega
    if (isEmpty(tp))
    {
     printf("stack underflow \n");
    }else
    {
        struct node* n=tp;
        top= (tp)->next;
        int x=n->data;
        free(n);
        return x;

    }
    
    
}

int peek(int position){
    struct node * ptr= top;
    for (int i = 0; (i < position-1 && ptr !=NULL); i++)
    {
        ptr=ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
    
}




int main(){
    
    top =push(top ,30);
    top =push(top ,111);
    top =push(top ,3);
    top =push(top ,3444);

    
    
    linkedListTraversal(top);

   for (int i = 1; i <= 4; i++)
   {
    printf("value at position %d is : %d \n",i,peek(i));
   }
   
   printf("top most value of this stack is %d \n",stackTop(top));
printf("bottom most value of this stack is %d \n",stackBottom(top));

    return 0;

}