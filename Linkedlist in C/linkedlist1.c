#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the end of the list
void delete_from_end(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = *head_ref;
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        printf("Deleted the last element.\n");
        return;
    }
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    printf("Deleted the last element.\n");
}

// Function to traverse and display all elements in the list
void display_list(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert element at the end\n");
        printf("2. Delete node from the end\n");
        printf("3. Display all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;

            case 2:
                delete_from_end(&head);
                break;

            case 3:
                display_list(head);
                break;

            case 4:
                // Free all allocated nodes
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

