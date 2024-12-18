#include <stdio.h> 
#include <stdlib.h> 
// Define a structure for a linked list node 
struct Node { 
int data; 
struct Node* next; 
}; 
// Function to create a new node 
struct Node* createNode(int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
newNode->next = NULL; 
return newNode; 
} 
// Function to insert a node at the end of the list 
void insertAtEnd(struct Node** head, int value) { 
struct Node* newNode = createNode(value); 
if (*head == NULL) { 
*head = newNode; 
return; 
} 
struct Node* temp = *head; 
while (temp->next != NULL) { 
temp = temp->next; 
} 
temp->next = newNode; 
} 
// Function to delete a node with a specific value 
void deleteNode(struct Node** head, int value) { 
    struct Node* temp = *head; 
    struct Node* prev = NULL; 
 
    // If the head node itself holds the value to be deleted 
    if (temp != NULL && temp->data == value) { 
        *head = temp->next; // Update head 
        free(temp);         // Free old head 
        printf("Deleted node with value %d\n", value); 
        return; 
    } 
 
    // Search for the node to be deleted 
    while (temp != NULL && temp->data != value) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    // If the value is not found 
    if (temp == NULL) { 
        printf("Value %d not found in the list.\n", value); 
        return; 
    } 
 
    // Unlink the node from the linked list 
    prev->next = temp->next; 
    free(temp); 
    printf("Deleted node with value %d\n", value); 
} 
 
// Function to display the linked list 
void displayList(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
    printf("Linked List: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, value; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert a node at the end\n"); 
        printf("2. Delete a node by value\n"); 
        printf("3. Display the list\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insertAtEnd(&head, value); 
                break; 
            case 2: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                deleteNode(&head, value); 
                break; 
            case 3: 
                displayList(head); 
                break; 
            case 4: 
                printf("Exiting program.\n"); 
                return 0; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
 
    return 0; 
}