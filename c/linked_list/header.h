#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

// Define the size of a Node for memory allocation
#define SIZEOFNODE sizeof(Node)

// Define the size of a List for memory allocation
#define SIZEOFLIST sizeof(List)

// Structure representing a single node in the linked list
typedef struct node {
    int data;                // Data value stored in the node
    struct node *next;      // Pointer to the next node in the list
} Node;

// Structure representing the linked list itself
typedef struct {
    int length;             // Current number of nodes in the list
    Node *head;            // Pointer to the first node in the list
    Node *tail;            // Pointer to the last node in the list
} List;

// Function to initialize a new node and allocate memory for it
Node *initializeNode() {
    Node *node = (Node *)malloc(SIZEOFNODE); // Allocate memory for a new node
    return node; // Return the pointer to the newly created node
}

// Function to initialize a new linked list and set its initial values
List *initialLizeList() {
    List *list = (List *)malloc(SIZEOFLIST); // Allocate memory for the list
    list->length = 0;   // Set initial length to 0 (empty list)
    list->head = NULL;  // Set head pointer to NULL (no nodes yet)
    list->tail = NULL;  // Set tail pointer to NULL (no nodes yet)
    return list; // Return the initialized list
}

// Function to create a new node with specified data
Node *createNode(int data) {
    Node *temp = initializeNode(); // Initialize a new node
    temp->data = data; // Set the node's data value
    return temp; // Return the newly created node
}

// Function to insert a new node at a specified position in the list
void insertNode(Node **head, Node **tail, int *length, int data, int position) {
    Node *temp = createNode(data); // Create a new node with the given data

    if (position == 1) { // Check if inserting at the head of the list
        temp->next = *head; // Link new node to the current head
        *head = temp; // Update head pointer to the new node
    } else {
        int i = 1; // Initialize a counter for traversal
        Node *iterator = *head; // Start from the head of the list
        // Traverse to the node just before the desired position
        while (i < position - 1) {
            iterator = iterator->next; // Move to the next node
            i++; // Increment the counter
        }
        temp->next = iterator->next; // Link new node to the next node
        iterator->next = temp; // Insert the new node into the list
    }
    if (*length == 0) // Check if the list was empty before insertion
        *tail = *head; // Update the tail to point to the new head
    
    *length = *length + 1; // Increase the length of the list by 1
}

// Function to delete a node at a specified position in the list
void deleteNode(Node **head, Node **tail, int *length, int position) {
    // Check if the position is valid
    if (position > *length)
        printf("Invalid Position\n"); // Print an error message if invalid

    int i = 1; // Initialize a counter for traversal
    Node *iterator = *head; // Start from the head of the list

    // Traverse to the node just before the one to be deleted
    while (i < position - 1) {
        iterator = iterator->next; // Move to the next node
        i++; // Increment the counter
    }
    
    // Handle deletion based on the position
    if (position == 1) { // Special case for deleting the head node
        Node *tofree = iterator; // Get the node to delete
        *head = tofree->next; // Update head to the next node
        printf("\ndeleted[%d]\n", tofree->data); // Print the deleted node's data
        free(tofree); // Free the memory of the deleted node
    } else if (position == *length) { // Special case for deleting the tail node
        printf("\ndeleted[%d]\n", iterator->next->data); // Print the deleted node's data
        iterator->next = NULL; // Unlink the tail node
        free(iterator->next); // Free memory (incorrect usage, see note)
    } else { // Deleting a node in the middle of the list
        Node *tofree = iterator->next; // Get the node to delete
        iterator->next = tofree->next; // Link previous node to the next node
        printf("\ndeleted[%d]\n", tofree->data); // Print the deleted node's data
        free(tofree); // Free the memory of the deleted node
    }

    *length = *length - 1; // Decrease the length of the list by 1
    printf("\nLENGTH=[%d]\n", *length); // Print the updated length of the list
}

// Function to print the contents of the linked list
void printList(Node *head) {
    printf("\n");
    // Check if the list is empty
    if (head == NULL)
        printf("List is Empty"); // Print message if the list is empty

    Node *temp = head; // Start from the head of the list
    // Traverse the list and print each node's data
    while (temp != NULL) {
        printf("<-[%d]\t", temp->data); // Print the node's data
        temp = temp->next; // Move to the next node
    }
    free(temp); 
    printf("\n");
}

#endif
