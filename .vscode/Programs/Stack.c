#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
    int maxTop;
    int maxItems[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->maxTop = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
    
    // Update the max stack
    if (s->maxTop == -1 || value >= s->maxItems[s->maxTop]) {
        s->maxItems[++s->maxTop] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate error
    }
    
    int poppedValue = s->items[s->top--];

    // Update the max stack if necessary
    if (poppedValue == s->maxItems[s->maxTop]) {
        s->maxTop--;
    }

    return poppedValue;
}

int getMax(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate error
    }
    return s->maxItems[s->maxTop];
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print Max\n4. Print Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = getMax(&s);
                if (value != -1) {
                    printf("Max element in the stack: %d\n", value);
                }
                break;
            case 4:
                printStack(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
