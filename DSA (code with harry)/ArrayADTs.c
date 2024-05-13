#include<stdio.h>
#include<STDLIB.H>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tsize, int usize){

    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr=(int *)malloc(tsize *sizeof(int));

 //we can also write these aboev code using arrow  opreator 
    a->total_size=tsize;
    a->used_size=usize;
    a-> ptr=(int *)malloc(tsize *sizeof(int));

}

//showing the entered values
void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d \n",(a->ptr)[i]);
    }
    
}

//inputing the values from user in array
void setvalue(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("enter element %d :",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    
}


int main(){

    struct myArray marks;
    createArray(&marks ,100,2); //creating 100 memory space and giving 2 for use
    printf("we are running setvalue function \n");
    setvalue(&marks);
    printf("we are running show function \n");
    show(&marks);

return 0 ;
}