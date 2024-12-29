#include <stdio.h>
#include <stdlib.h>

// Definition of the BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is equal, do not insert duplicates
    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to count the number of nodes in the BST
int countNodes(Node* root) {
    if(root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to search for a particular element in the BST
int searchBST(Node* root, int key) {
    if(root == NULL)
        return 0; // Not found
    if(key == root->data)
        return 1; // Found
    else if(key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Function to calculate the height of the BST
int height(Node* root) {
    if(root == NULL)
        return -1; // Height of empty tree is -1
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Binary Search Tree Operations ===\n");
    printf("1. Insert a node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Count the number of nodes\n");
    printf("6. Search for an element\n");
    printf("7. Calculate the height of the tree\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Node* root = NULL;
    int choice, value;
    while(1) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST.\n", value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Number of nodes in the BST: %d\n", countNodes(root));
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if(searchBST(root, value))
                    printf("%d is present in the BST.\n", value);
                else
                    printf("%d is NOT present in the BST.\n", value);
                break;
            case 7:
                printf("Height of the BST: %d\n", height(root));
                break;
            case 8:
                printf("Exiting program.\n");
                // Free memory (optional)
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

