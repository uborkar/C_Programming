#include <stdio.h>
#include <stdlib.h>
int i;
// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to create the doubly linked list with the first node
void create_list(Node** head_ref, int data) {
    if (*head_ref != NULL) {
        printf("List already exists. Use insert to add more nodes.\n");
        return;
    }
    Node* new_node = create_node(data);
    *head_ref = new_node;
    printf("List created with element %d.\n", data);
}

// Function to insert a node after a specific location
void insert_after_location(Node** head_ref, int location, int data) {
    if (*head_ref == NULL) {
        printf("List is empty. Create the list first.\n");
        return;
    }

    Node* new_node = create_node(data);
    Node* temp = *head_ref;

    for (i = 1; i < location; i++) {
        if (temp->next == NULL && i < location - 1) {
            printf("Invalid location. List has fewer nodes.\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    new_node->prev = temp;
    temp->next = new_node;

    printf("Inserted %d after location %d.\n", data, location);
}

// Function to delete a node after a specific location
void delete_after_location(Node** head_ref, int location) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head_ref;

    for (i = 1; i < location; i++) {
        if (temp->next == NULL) {
            printf("Invalid location. List has fewer nodes.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("No node exists after the given location.\n");
        return;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    if (node_to_delete->next != NULL) {
        node_to_delete->next->prev = temp;
    }
    free(node_to_delete);

    printf("Deleted node after location %d.\n", location);
}

// Function to search for a specific element in the list
void search_element(Node* head, int key) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element %d not found in the list.\n", key);
}

// Function to print the minimum and maximum values in the list
void print_min_max(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int min = head->data;
    int max = head->data;
    Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

// Function to traverse and display all elements in the list
void traverse_list(Node* head) {
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
    int choice, data, location;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create list\n");
        printf("2. Insert node after specific location\n");
        printf("3. Delete node after specific location\n");
        printf("4. Search for an element\n");
        printf("5. Print minimum and maximum values\n");
        printf("6. Traverse and display elements\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to create the list: ");
                scanf("%d", &data);
                create_list(&head, data);
                break;

            case 2:
                printf("Enter the location after which to insert: ");
                scanf("%d", &location);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_after_location(&head, location, data);
                break;

            case 3:
                printf("Enter the location after which to delete: ");
                scanf("%d", &location);
                delete_after_location(&head, location);
                break;

            case 4:
                printf("Enter the element to search for: ");
                scanf("%d", &data);
                search_element(head, data);
                break;

            case 5:
                print_min_max(head);
                break;

            case 6:
                traverse_list(head);
                break;

            case 7:
                printf("Exiting...\n");
                // Free all allocated nodes
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}

