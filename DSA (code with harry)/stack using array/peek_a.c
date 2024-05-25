#include<STDIO.H>
#include<STDLIB.H>

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
    }
    return 0;
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
    
}


void push(struct stack *ptr, int val){
    if (isFull(ptr))
    {
      printf("stack is overflow ! cannot push %d to the stack \n",val);
    }else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
    
    
}

int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        /* code */
        printf("stack is underflow \n");
        return -1;
    }else
    {
        int val=ptr->arr[ptr->top];
        ptr->top -- ;
        return val;
    }
    
    
}

int peek(struct stack * s, int i){
    int arrayIndex= s->top -i +1;
    if (arrayIndex < 0)
    {
        printf("not a valid position for the stack \n");
        return -1;
    }else
    {
        return s->arr[arrayIndex];
    }
    
    
}


int main(){
    struct stack *s;
    s->size=5;
    s->top = -1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    printf("stack has been created \n");

    push(s, 123);
    push(s, 13);
    push(s, 3);
    push(s, 1123);
    push(s, 124);


    for (int j = 0; j <= s->top +1; j++)
    {
       printf("the value at position %d is %d \n", j,peek(s,j));
     }
    return 0;
}
