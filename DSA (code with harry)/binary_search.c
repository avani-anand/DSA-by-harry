//binary search for sorted in asccending order 
#include<stdio.h>
int binarySearch(int arr[],int size,int element ){
    int low,mid ,high;
    low=0;
    high =size-1;
    //keep searching until low<=high
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low= mid+1;
        }
        else{
            high =mid-1;
        }
        
    }
    return -1;
}


int main(){
    //sorted array
int arr[]={12,23,44,56,333,507,545};
int size= sizeof(arr)/sizeof(int); //for knowing the size of our arr
int element=333;
int searchIndex=binarySearch(arr,size,element);
printf("the element %d was found at index %d \n", element,searchIndex);
return 0 ;
}