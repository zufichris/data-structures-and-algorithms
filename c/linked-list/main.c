#include "header.h"

int main() {
    // Initialize the linked list
    List *list = initialLizeList();
    int length;

    // Prompt the user to enter the number of elements to insert
    printf("\nEnter Number Of Elements: \n");
    scanf("%d", &length);

    // Validate the input length; it must be greater than 0
    if (length < 1) {
        printf("Invalid Length\n");
        return 0; // Exit the program if the length is invalid
    }

    // Insert nodes into the list based on the specified length
    for (int i = 0; i < length; i++) {
        int data;
        // Prompt the user to enter the data for each node
        printf("\nEnter Node[%d]:\t", i + 1);
        scanf("%d", &data);
        // Insert the node at the end of the list (1-based index)
        insertNode(&list->head, &list->tail, &list->length, data, i + 1);
    }

    // Display the current state of the list
    printList(list->head);

    // Prompt the user to enter a position to insert a new node
    int position;
    printf("\nEnter Position To Insert:\t");
    scanf("%d", &position);
    int data;
    // Prompt the user for the data to insert at the specified position
    printf("\nEnter Data To Insert At [%d]:\t", position);
    scanf("%d", &data);
    // Insert the new node at the specified position
    insertNode(&list->head, &list->tail, &list->length, data, position);
    // Display the updated list
    printList(list->head);

    // Prompt the user to enter a position to delete a node
    printf("\nEnter Position To Delete:\t");
    scanf("%d", &position);
    // Delete the node at the specified position
    deleteNode(&list->head, &list->tail, &list->length, position);
    // Display the list after deletion
    printList(list->head);

    // Clean up and free any allocated memory for the list (optional, but recommended)
    free(list);

    return 0;
}
