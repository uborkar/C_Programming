#include <stdio.h>


int circularQueue[4];  // Array to store elements
int front = -1, rear = -1;  // Pointers to front and rear of the queue

// Function to check if the Circular Queue is full (Overflow)
int isFull() {
    if ((front == 0 && rear == 4 - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

// Function to check if the Circular Queue is empty (Underflow)
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the Circular Queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add %d\n", value);
    } else {
        if (front == -1)  // Inserting the first element
            front = 0;
        rear = (rear + 1) % 4;  // Move rear to the next position circularly
        circularQueue[rear] = value;
        printf("%d added to the queue.\n", value);
    }
}

// Function to delete an element from the Circular Queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot remove element.\n");
    } else {
        printf("%d removed from the queue.\n", circularQueue[front]);
        if (front == rear) {  // Queue has only one element, now it's empty
            front = rear = -1;
        } else {
            front = (front + 1) % 4;  // Move front to the next position circularly
        }
    }
}

// Function to display the elements in the Circular Queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        int i = front;
        printf("Circular Queue elements: ");
        while (i != rear) {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % 4;
        }
        printf("%d\n", circularQueue[rear]);  // Print the last element
    }
}

// Main function to demonstrate the Circular Queue operations
int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

