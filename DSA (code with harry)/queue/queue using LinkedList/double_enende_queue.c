#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to insert an element at the front
void insertFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("Inserted %d at the front\n", data);
}

// Function to insert an element at the rear
void insertRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Inserted %d at the rear\n", data);
}

// Function to delete an element from the front
void deleteFront(Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty, cannot delete from front\n");
        return;
    }
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    printf("Deleted %d from the front\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear
void deleteRear(Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty, cannot delete from rear\n");
        return;
    }
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    printf("Deleted %d from the rear\n", temp->data);
    free(temp);
}

// Function to display the deque from front to rear
void displayDeque(Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = deque->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the deque operations
int main() {
    Deque* deque = createDeque();

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    insertRear(deque, 25);

    displayDeque(deque);

    deleteFront(deque);
    deleteRear(deque);

    displayDeque(deque);

    // Free remaining nodes and deque
    while (deque->front != NULL) {
        deleteFront(deque);
    }
    free(deque);

    return 0;
}
