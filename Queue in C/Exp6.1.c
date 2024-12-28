#include <stdio.h>
#define MAX 5
int i;
int linearQueue[MAX], linearFront = -1, linearRear = -1;
int circularQueue[MAX], circularFront = -1, circularRear = -1;
int isLinearFull() {
    if (linearRear == MAX - 1) return 1;
    return 0;
}
int isLinearEmpty() {
    if (linearFront == -1 || linearFront > linearRear) return 1;
    return 0;
}
void linearEnqueue(int value) {
    if (isLinearFull()) {
        printf("Linear Queue is full!\n");
    } else {
        if (linearFront == -1) linearFront = 0;
        linearRear++;
        linearQueue[linearRear] = value;
        printf("%d added to Linear Queue\n", value);
    }
}
void linearDequeue() {
    if (isLinearEmpty()) {
        printf("Linear Queue is empty!\n");
    } else {
        printf("%d removed from Linear Queue\n", linearQueue[linearFront]);
        linearFront++;
    }
}
void linearTraverse() {
    if (isLinearEmpty()) {
        printf("Linear Queue is empty!\n");
    } else {
        printf("Linear Queue: ");
        for (i = linearFront; i <= linearRear; i++) {
            printf("%d ", linearQueue[i]);
        }
        printf("\n");
    }
}
int isCircularFull() {
    if ((circularFront == (circularRear + 1) % MAX)) return 1;
    return 0;
}
int isCircularEmpty() {
    if (circularFront == -1) return 1;
    return 0;
}
void circularEnqueue(int value) {
    if (isCircularFull()) {
        printf("Circular Queue is full!\n");
    } else {
        if (circularFront == -1) circularFront = 0;
        circularRear = (circularRear + 1) % MAX;
        circularQueue[circularRear] = value;
        printf("%d added to Circular Queue\n", value);
    }
}
void circularDequeue() {
    if (isCircularEmpty()) {
        printf("Circular Queue is empty!\n");
    } else {
        printf("%d removed from Circular Queue\n", circularQueue[circularFront]);
        if (circularFront == circularRear) {
            circularFront = circularRear = -1;  // Queue becomes empty
        } else {
            circularFront = (circularFront + 1) % MAX;
        }
    }
}
void circularTraverse() {
    if (isCircularEmpty()) {
        printf("Circular Queue is empty!\n");
    } else {
        printf("Circular Queue: ");
        int i = circularFront;
        while (i != circularRear) {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", circularQueue[circularRear]);
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Linear Enqueue\n2. Linear Dequeue\n3. Linear Traverse\n");
        printf("4. Circular Enqueue\n5. Circular Dequeue\n6. Circular Traverse\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue in Linear Queue: ");
                scanf("%d", &value);
                linearEnqueue(value);
                break;
            case 2:
                linearDequeue();
                break;
            case 3:
                linearTraverse();
                break;
            case 4:
                printf("Enter value to enqueue in Circular Queue: ");
                scanf("%d", &value);
                circularEnqueue(value);
                break;
            case 5:
                circularDequeue();
                break;
            case 6:
                circularTraverse();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

