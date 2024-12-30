// cModule.c
#include "cModule.h"

struct node{
    int data;
    struct node *next;
};

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

void printLinkedLst(struct node *p)
{
    while(p!=NULL)
    {
        printf("Data: %d \n", p->data);
        p = p->next;
    }
}

void cFunction() {
    printf("C function is imported in cpp project successfully!\n");

    struct node *head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head = insertFront(head, 50);
    printLinkedLst(head);
}
