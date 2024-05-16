#include<stdio.h>
#include<stdlib.H>


struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal (struct Node *head){
 struct Node *ptr=head;

//    printf("element is %d\n", ptr->data);  // phle ek item ko print krva dite h taki while loop chle
//    ptr=ptr->next;
//    //we should use do while for this 
//   while (ptr !=head) //while loop hum start kr rhe h ptr!=head but starting m to ptr to head ko hi point kr rha isliye loop chlega hi ni isliye ek bar phle item ko upar print krva diye h
//   {
//     printf("element is %d\n", ptr->data);
//     ptr=ptr->next;
//   }
  
    do
    {
         printf("element is %d\n", ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    

}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

//allocating memory for nodes in the linked list in heap
// we have to give every node a new memory because they are not contigous to memory
     head=(struct Node *)malloc (sizeof(struct Node)); //giving memory to head node 
     second=(struct Node *)malloc (sizeof(struct Node)); //giving memory to second node
     third=(struct Node *)malloc (sizeof(struct Node)); //giving memory to third node
     fourth=(struct Node *)malloc (sizeof(struct Node)); //giving memory to fourth node


     //linking first(head) and second nodes
     head->data=4;
     head->next=second;

     //linking second and third nodes
     second->data=3;
     second->next=third;

     //linking third and fourth nodes
     third->data=6;
     third->next=fourth;

     //terminatiing the list at the fourth node
     fourth->data=1;
     fourth->next=head;

     linkedListTraversal(head); //passing head to function because alll are linked with it


return 0 ;
}