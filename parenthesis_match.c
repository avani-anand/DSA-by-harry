#include<stdio.h>
#include<STDLIB.H>


struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if (ptr->top == -1)
    {
       return 1;
    }
    else return 0;
    
}

int isFull(struct stack * ptr){
    if (ptr->top == ptr->size -1)
    {
        return 1;
    } else return 0;
    
}

void push(struct stack *ptr , char val){
  if (isFull(ptr))
  {
   printf("stack is overflow  ! cannot push %d to the stack\n",val);
  }else
  {
    ptr->top++;
    ptr->arr[ptr->top]=val;
  }

}


char pop(struct stack *ptr ){
  if (isEmpty(ptr))
  {
   printf("stack is underflow \n");
   return -1; 


  }else
  {
    int val =ptr->arr[ptr->top];
    ptr->top--;
    return val;

  }

}


int parenthesisMatch(char * exp){
    //create and initializw the stack

    struct stack * sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));


for (int i = 0; exp[i] != '\0'; i++)
{
    if (exp[i]== '(')
    {
        push(sp , '(');
    }else if (exp[i]== ')')
    {
        if (isEmpty(sp))
        {
            return 0;
        }
        
        pop(sp);
    }
    
    
}

if (isEmpty(sp))
{
    return 1;

}else
{
    return 0;
}



}



int main(){
 //check if stack is empty

 char * exp= "2*(44)-3)";
  
 if (parenthesisMatch(exp))
 {
    printf("the parenthesis is matching");
 }
 else
 {
    printf("the parenthesis is not matching");
 }
 
 


return 0 ;
}