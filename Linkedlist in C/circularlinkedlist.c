#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the circular linked list
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
 new_node->next = new_node; // Point to itself (circular reference)
 return new_node;
}
// Function to insert a node after a specific location
void insert_after(Node** head_ref, int after_data, int new_data) {
 Node* new_node = create_node(new_data);
 if (*head_ref == NULL) {
 *head_ref = new_node;
 return;
 }
 
 Node* temp = *head_ref;
 do {
 if (temp->data == after_data) {
 new_node->next = temp->next;
 temp->next = new_node;
 return;
 }
 temp = temp->next;
 } while (temp != *head_ref);
 printf("Node with data %d not found.\n", after_data);
}
// Function to delete the node after a specific location
void delete_after(Node** head_ref, int after_data) {
 if (*head_ref == NULL) {
 printf("List is empty.\n");
 return;
 }
 Node* temp = *head_ref;
 do {
 if (temp->data == after_data) {
 Node* node_to_delete = temp->next;
 if (node_to_delete == *head_ref) {
 printf("Cannot delete: No node after %d.\n", after_data);
 return;
 }
 temp->next = node_to_delete->next;
 free(node_to_delete);
 return;
 }
 temp = temp->next;
 } while (temp != *head_ref);
 printf("Node with data %d not found.\n", after_data);
}
// Function to search for a specific element in the list
Node* search(Node* head, int target) {
 Node* temp = head;
 if (head == NULL) return NULL;
 do {
 if (temp->data == target) return temp;
 temp = temp->next;
 } while (temp != head);
 return NULL;
}
// Function to traverse and display all elements in the list
void display_list(Node* head) {
 if (head == NULL) {
 printf("The list is empty.\n");
 return;
 }
 Node* temp = head;
 printf("List elements: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } while (temp != head);
 printf("\n");
}
int main() {
 Node* head = NULL;
 int choice, data, after_data;
 while (1) {
 printf("\nCircular Linked List Operations:\n");
 printf("1. Insert node after specific location\n");
 printf("2. Delete node after specific location\n");
 printf("3. Search for a specific element\n");
 printf("4. Display all elements\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the data to insert after: ");
 scanf("%d", &after_data);
 printf("Enter the new data to insert: ");
 scanf("%d", &data);
 insert_after(&head, after_data, data);
 break;
 case 2:
 printf("Enter the data to delete node after: ");
 scanf("%d", &after_data);
 delete_after(&head, after_data);
 break;
 case 3:
 printf("Enter the data to search for: ");
 scanf("%d", &data);
 Node* result = search(head, data);
 if (result) {
 printf("Element %d found in the list.\n", data);
 } else {
 printf("Element %d not found in the list.\n", data);
 }
 break;
 case 4:
 display_list(head);
 break;
 case 5:
 // Free all allocated nodes
 if (head != NULL) {
 Node* temp = head;
 Node* next_node;
 do {
 next_node = temp->next;
 free(temp);
 temp = next_node;
 } while (temp != head);
 }
 printf("Exiting...\n");
 exit(0);
 default:
 printf("Invalid choice! Please enter a number between 1 and 5.\n");
 }
 }
 return 0;
}

