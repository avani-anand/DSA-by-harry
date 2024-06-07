#include<stdio.h>
#include<STDLIB.H>

struct circularQueue
{
    int size;
    int f;
    int r;
    int * arr;
};


int isFull(struct circularQueue *q){  
    if ((q->r+1)%q->size ==q->f)
    {
        return 1;
    }
        return 0;
    
}

int isEmpty(struct circularQueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
        return 0;
    
}

void enqueue(struct circularQueue *q,int val){
    if (isFull(q))
    {
        printf(":this queue is full");
    }
    else
    {
        q->r= (q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enqueued elements : %d \n",val);

    }
    
}


int dequeue(struct circularQueue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("this queue is full");
    } 
    else
    {
        q->f =(q->f+1) %q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
struct circularQueue q;
q.size=4;
q.f=q.r=0;  //we can not intilize the circular queue by -1 because in circular queue by using -1 its goes to infinite also in circular queue it store one element is less than the given size of the queue so here we give 4 as size but it will only store 3 elements
q.arr=(int *)malloc(q.size*sizeof(int));


//ENQUEUING FEW ELEMENTS

enqueue(&q,122);
enqueue(&q,122);
enqueue(&q,122);
// enqueue(&q,1221);

printf("dequeue element %d \n", dequeue(&q));
printf("dequeue element %d \n", dequeue(&q));
// printf("dequeue element %d \n", dequeue(&q));
// printf("dequeue element %d \n", dequeue(&q));
enqueue(&q,122);
enqueue(&q,122);

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