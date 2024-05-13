#include<stdio.h>

int linearSearch(int arr[], int size , int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main(){
int arr[]={12,23,44,56,75,3,567,545,74,56};
int size= sizeof(arr)/sizeof(int); //for knowing the size of our arr
int element=75;
int searchIndex=linearSearch(arr,size,element);
printf("the element %d was found at index %d \n", element,searchIndex);
return 0 ;
}