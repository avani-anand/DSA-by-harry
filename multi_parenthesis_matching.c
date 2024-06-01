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

char stackTop(struct stack * sp){
    return sp->arr[sp->top];
 }

int match(char a, char b){
    if (a=='{' && b== '}')
    {
       return 1;
    }
    if (a=='(' && b== ')')
    {
       return 1;
    }
    if (a=='[' && b== ']')
    {
       return 1;
    }
    
        return 0;
   
    
}




int parenthesisMatch(char * exp){
    //create and initializw the stack

    struct stack * sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char popped_ch;

for (int i = 0; exp[i] != '\0'; i++)
{
    if (exp[i]== '(' || exp[i]=='{' || exp[i]== '[')
    {
        push(sp , exp[i]);
    }else if (exp[i]== ')' || exp[i]=='}' || exp[i]==']')
    {
        if (isEmpty(sp))
        {
            return 0;
        }
        
     popped_ch=  pop(sp);

     if (! match(popped_ch , exp[i]))
     {
        /* code */ return 0;
     }
     
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
 

char *exp= "([(8)(*4)])";
// char *exp= "8+89(43)+[324]*{3}";
// char *exp= "((8)(*4))}";
  
 if (parenthesisMatch(exp))
 {
    printf("the expression is balanced");
 }
 else
 {
    printf("the expression is unbalanced ");
 }
 
 


return 0 ;
}