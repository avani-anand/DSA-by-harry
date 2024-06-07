#include<stdio.h>
#include<STDLIB.H>

struct queue
{
    int size;
    int f;
    int r;
    int * arr;
};


int isFull(struct queue *q){
    if (q->r == q->size-1)
    {
        return 1;
    }
        return 0;
    
}

int isEmpty(struct queue *q){
    if (q->r == q->f)
    {
        return 1;
    }
        return 0;
    
}

void enqueue(struct queue *q,int val){
    if (isFull(q))
    {
        printf(":this queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("enqueued elements : %d \n",val);

    }
    
}


int dequeue(struct queue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("this queue is full");
    } 
    else
    {
        q->f++;
        a=q->arr[q->f];
       
    }
    return a;
}

int main(){
struct queue q;
q.size=4;
q.f=q.r=-1;
q.arr=(int *)malloc(q.size*sizeof(int));


//ENQUEUING FEW ELEMENTS

enqueue(&q,122);
enqueue(&q,1221);
enqueue(&q,12213);
enqueue(&q,12212);

printf("dequeue element %d \n", dequeue(&q));
printf("dequeue element %d \n", dequeue(&q));







if (isEmpty(&q))
{
    printf("queue is empty \n"); 
}

if (isFull(&q))
{
  printf("queue is full \n");
}


return 0 ;
}