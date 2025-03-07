#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtHead(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void insertAtTail(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
    {  
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void traverseForward(Node* head) 
{
    printf("Forward: ");
    Node* temp = head;
    while (temp != NULL)
     {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void traverseBackward(Node* head)
{
    if (head == NULL) return;
    
    // Move to the last node
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    Node* head = NULL;
    int choice, value;

    while (1)
    {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;
            case 3:
                traverseForward(head);
                break;
            case 4:
                traverseBackward(head);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
