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

void push(struct stack *ptr , int val){
  if (isFull(ptr))
  {
   printf("stack is overflow  ! cannot push %d to the stack\n",val);
  }else
  {
    ptr->top++;
    ptr->arr[ptr->top]=val;
  }

}


int pop(struct stack *ptr ){
  if (isEmpty(ptr))
  {
   printf("stack is underflow \n");
   return -1; //have to return something then assuming that in our stack -1 never come so returning here -1 if stack is underflow


  }else
  {
    int val =ptr->arr[ptr->top];
    ptr->top--;
    return val;

  }

}

int main(){
struct stack *s;
s->size=10;
s->top=-1;
s->arr=(int *)malloc(s->size* sizeof(int));
printf("stack has been created \n");

printf("before pushing , full :%d\n",isFull(s));
printf("before pushing , Empty :%d\n",isEmpty(s));
push(s, 34535);
push(s, 345);
push(s, 34535);
push(s, 535);
push(s, 4535);
push(s, 3435);
push(s, 34535);
push(s, 34535);
push(s, 34535);

push(s, 3455);  // ---->pushed 10 values
push(s, 345);   //here on this pushing is not done because stack overflow since the size of the stack is 10
printf("after pushing , full :%d\n",isFull(s));
printf("after pushing , Empty :%d\n",isEmpty(s));


printf("popped %d from the stack \n", pop(s));
printf("popped %d from the stack \n", pop(s));
printf("popped %d from the stack \n", pop(s));
printf("popped %d from the stack \n", pop(s));

return 0 ;
}