#include <stdio.h>  
#include <stdlib.h>  
#define SIZE 4  
int top = -1, inp_array[SIZE];  
void push();  
void pop();  
void getmax();
void show();  
int main()  
{  
    int choice;  
    while (1)  
    {  
        printf("\nPerform operations on the stack:");  
        printf("\n1.Push the element\n2.Pop the element\n3.Getmax\n4.Show\n5.End");  
        printf("\n\nEnter the choice: ");  
        scanf("%d", &choice);  
        switch (choice)  
        {  
        case 1:  
            push();  
            break;  
        case 2:  
            pop();  
            break;  
        case 3:
            getmax();
            break;
        case 4:  
            show();  
            break;  
        case 5:  
            exit(0);  
        default:  
            printf("\nInvalid choice!!");  
        }  
    }  
}  
void push()  
{  
    int x;  
    if (top == SIZE - 1)  
    {  
        printf("\nOverflow!!");  
    }  
    else  
    {  
        printf("\nEnter the element to be added onto the stack: ");  
        scanf("%d", &x);  
        top = top + 1;  
        inp_array[top] = x;  
    }  
}  
void pop()  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nPopped element: %d", inp_array[top]);  
        top = top - 1;  
    }  
}  
void getmax()
{
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    int max = inp_array[0];
    for (int i = 1; i <= top; i++) {
        if (inp_array[i] > max) {
            max = inp_array[i];
        }
    }
    printf("\nMaximum Element is: %d",max);
}
void show()  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nElements present in the stack: \n");  
        for (int i = top; i >= 0; --i)  
            printf("%d\n", inp_array[i]);  
    }  
} 