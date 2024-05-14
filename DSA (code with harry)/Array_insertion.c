#include<stdio.h>

void display(int arr[], int n){
    // code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n");
}

int indexInsertion (int arr[], int size , int elemnt , int capacity, int index){
   //code for insertion
    if (size >=capacity)
    {
        return -1;
    }

    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=elemnt;
    return 1;
    
    
}

int main(){
   int arr[100]={7,8,12,27,88};
   int size = 5, elemnt=45;
  int index=3;
   display(arr,size);
   indexInsertion(arr, size, elemnt,100,index);
   size +=1;
   display(arr,size);


return 0 ;
}