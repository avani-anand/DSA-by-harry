#include<stdio.h>
#include<stdlib.h>
struct stack
{
    /* data */
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack * ptr){
    if (ptr->top == -1)
    {
        return 1;

    } return 0;
    
}
int isFull(struct stack * ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;

    } return 0;
    
}

int main(){
struct stack *s;
s->size=70;
s->top=-1;
s->arr=(int *)malloc(s->size* sizeof(int));
//pushing an elment manually
s->arr[0]=7;
s->top++;

//check if stack is empty

if (isEmpty(s))
{
    printf("stack is empty \n");
}
else
{
    printf("stack is not empty \n");
    /* code */
}


return 0 ;
}