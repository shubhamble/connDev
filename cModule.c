// cModule.c
#include "cModule.h"

struct node{
    int data;
    struct node *next;
};

void bubbleSortList(struct node* head) {
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    // Check if the list is empty
    if (head == NULL)
        return;

    do {
        swapped = 0;  // Flag to check swapping
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1; // Set swapped to true
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Update the last pointer
    } while (swapped); // Continue until no swaps occur
}

struct node *newNode(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* insertFront(struct node *head, int new_data)
{
    struct node* new_node = newNode(new_data);
    new_node->next = head;
    return new_node;
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;   // Previous node
    struct node* curr = head;  // Current node
    struct node* next = NULL;  // Next node

    while (curr != NULL)
    {
        // Store the next node
        next = curr->next;

        // Reverse the current node's pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }
    // Return the new head of the reversed list
    return prev;
}

void printLinkedLst(struct node *p)
{
    printf("Data:");
    while(p!=NULL)
    {
        printf(" %d \t", p->data);
        p = p->next;
    }
    printf("\n");
}

void cFunction()
{
    printf("C function is imported in cpp project successfully!\n");

    struct node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head = insertFront(head, 50);
    printf("Showing current linked list:\n");
    printLinkedLst(head);
    char c;
    printf("Do you want to reverse this linked list. Y/N:\n");
    scanf("%c", &c);
    if (c == 'Y' || c == 'y')
    {
        head = reverseList(head);
        printf("Linked list after reverse: \n");
        printLinkedLst(head);
    }
    else
    {
        printf("No changes made to the linked list.\n");
    }

    printf("Do you want to sort this linked list. Y/N:\n");
    getchar();
    scanf("%c", &c);
    if (c == 'Y' || c == 'y')
    { 
        // Sort the linked list using Bubble Sort
        bubbleSortList(head);

        printf("Linked List after sorting:\n");
        printLinkedLst(head);
    }
    else
    {
        printf("skipping the sorting of linked list.");
    }
}
