#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct LinearQueue {
    int items[MAX];
    int front;
    int rear;
} LinearQueue;

void initLinearQueue(LinearQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isLinearQueueFull(LinearQueue *q) {
    return q->rear == MAX - 1;
}

int isLinearQueueEmpty(LinearQueue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueueLinear(LinearQueue *q, int value) {
    if (isLinearQueueFull(q)) {
        printf("Linear Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeueLinear(LinearQueue *q) {
    if (isLinearQueueEmpty(q)) {
        printf("Linear Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}

void traverseLinear(LinearQueue *q) {
    if (isLinearQueueEmpty(q)) {
        printf("Linear Queue is empty\n");
        return;
    }
    printf("Linear Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

//### Circular Queue Implementation

typedef struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initCircularQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isCircularQueueFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isCircularQueueEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueueCircular(CircularQueue *q, int value) {
    if (isCircularQueueFull(q)) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeueCircular(CircularQueue *q) {
    if (isCircularQueueEmpty(q)) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue is now empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void traverseCircular(CircularQueue *q) {
    if (isCircularQueueEmpty(q)) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    LinearQueue linearQ;
    CircularQueue circularQ;
    initLinearQueue(&linearQ);
    initCircularQueue(&circularQ);

    int choice, value;
    while (1) {
        printf("\nSelect Queue Type:\n1. Linear Queue\n2. Circular Queue\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 3) break;

        if (choice == 1) {
            printf("\n1. Enqueue\n2. Dequeue\n3. Traverse\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueueLinear(&linearQ, value);
                    break;
                case 2:
                    value = dequeueLinear(&linearQ);
                    if (value != -1) {
                        printf("Dequeued: %d\n", value);
                    }
                    break;
                case 3:
                    traverseLinear(&linearQ);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } else if (choice == 2) {
            printf("\n1. Enqueue\n2. Dequeue\n3. Traverse\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueueCircular(&circularQ, value);
                    break;
                case 2:
                    value = dequeueCircular(&circularQ);
                    if (value != -1) {
                        printf("Dequeued: %d\n", value);
                    }
                    break;
                case 3:
                    traverseCircular(&circularQ);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } else {
            printf("Invalid queue type.\n");
        }
    }

    return 0;
}
