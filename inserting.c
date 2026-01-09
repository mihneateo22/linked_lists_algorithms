#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void deallocate(Node **head);
void insert_beginning(Node **head, int new_value);
void insert_end(Node **head, int new_value);
void insert_after(Node *node, int new_value);

int main()
{
    Node *head = malloc(sizeof(Node));
    head->value = 5;
    head->next = NULL;
    unsigned int i = 0;

    insert_end(&head, 1);
    insert_end(&head, 2);

    insert_beginning(&head, 0);

    insert_after(head->next, 7);

    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
    }
    deallocate(&head);
    return 0;
}

void deallocate(Node **head)
{
    Node *curr = *head;
    while(curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

void insert_beginning(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(2);
    new_node->value = new_value;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return ;
    }

    Node *curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

void insert_after(Node *node, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next = node->next;
    node->next = new_node;
}