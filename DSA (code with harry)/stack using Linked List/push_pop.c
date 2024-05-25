// this same program is done in another file  using global variable by making    " struct node* top= NULL;"  as a global variable
#include<STDIO.H>
#include<STDLIB.H>


struct node
{
    int data;
    struct node * next;
};


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



int pop(struct node** top){         //** means pointer of pointer  kyuki humne int main() k andar *top name ka local varibale bna diya h to ab yha ka *top ponter of pointer ho jaega
    if (isEmpty(*top))
    {
     printf("stack underflow \n");
    }else
    {
        struct node* n=*top;
        *top= (*top)->next;
        int x=n->data;
        free(n);
        return x;

    }
    
    
}




int main(){
    struct node* top= NULL;
    top =push(top ,30);
    top =push(top ,111);
    top =push(top ,3);

    int element=pop(&top);
    printf("popped element is %d \n",element);
    linkedListTraversal(top);


    return 0;

}