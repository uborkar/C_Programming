#include <stdio.h>
#include <stdlib.h>
int i;
// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
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
    new_node->next = NULL;
    return new_node;
}

// Function to create the circular linked list with the first node
void create_list(Node** tail_ref, int data) {
    if (*tail_ref != NULL) {
        printf("List already exists. Use insert to add more nodes.\n");
        return;
    }
    Node* new_node = create_node(data);
    new_node->next = new_node; // Point to itself to form a circular structure
    *tail_ref = new_node;
    printf("List created with element %d.\n", data);
}

// Function to insert a node after a specific location
void insert_after_location(Node** tail_ref, int location, int data) {
    if (*tail_ref == NULL) {
        printf("List is empty. Create the list first.\n");
        return;
    }
    Node* new_node = create_node(data);
    Node* temp = (*tail_ref)->next;
	int i;
    for (i = 1; i < location; i++) {
        temp = temp->next;
        if (temp == (*tail_ref)->next) { // Completed one full cycle
            printf("Invalid location. List has fewer nodes.\n");
            free(new_node);
            return;
        }
    }

    new_node->next = temp->next;
    temp->next = new_node;

    if (temp == *tail_ref) { // If inserted after the tail node, update the tail
        *tail_ref = new_node;
    }
    printf("Inserted %d after location %d.\n", data, location);
}

// Function to delete a node after a specific location
void delete_after_location(Node** tail_ref, int location) {
    if (*tail_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
	
    Node* temp = (*tail_ref)->next;
    for (i = 1; i < location; i++) {
        temp = temp->next;
        if (temp == (*tail_ref)->next) { // Completed one full cycle
            printf("Invalid location. List has fewer nodes.\n");
            return;
        }
    }

    Node* node_to_delete = temp->next;
    if (node_to_delete == temp) { // Only one node in the list
        free(node_to_delete);
        *tail_ref = NULL;
    } else {
        temp->next = node_to_delete->next;
        if (node_to_delete == *tail_ref) { // If the node to delete is the tail
            *tail_ref = temp;
        }
        free(node_to_delete);
    }
    printf("Deleted node after location %d.\n", location);
}

// Function to search for a specific element in the list
void search_element(Node* tail, int key) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = tail->next;
    int position = 1;

    do {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != tail->next);

    printf("Element %d not found in the list.\n", key);
}

// Function to traverse and display all elements in the list
void traverse_list(Node* tail) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = tail->next;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Main function
int main() {
    Node* tail = NULL;
    int choice, data, location;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create list\n");
        printf("2. Insert node after specific location\n");
        printf("3. Delete node after specific location\n");
        printf("4. Search for an element\n");
        printf("5. Traverse and display elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to create the list: ");
                scanf("%d", &data);
                create_list(&tail, data);
                break;

            case 2:
                printf("Enter the location after which to insert: ");
                scanf("%d", &location);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_after_location(&tail, location, data);
                break;

            case 3:
                printf("Enter the location after which to delete: ");
                scanf("%d", &location);
                delete_after_location(&tail, location);
                break;

            case 4:
                printf("Enter the element to search for: ");
                scanf("%d", &data);
                search_element(tail, data);
                break;

            case 5:
                traverse_list(tail);
                break;

            case 6:
                printf("Exiting...\n");
                // Free all allocated nodes
                if (tail != NULL) {
                    Node* temp = tail->next;
                    while (temp != tail) {
                        Node* next_node = temp->next;
                        free(temp);
                        temp = next_node;
                    }
                    free(tail);
                }
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}

