#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_after(Node *node, int new_value);
void insert_beginning(Node **head, int new_value);
void deallocate(Node **head);
void print_list(Node **head);
void insert_sorted(Node **head, int new_value);

int main()
{
    Node *head = NULL;
    insert_sorted(&head, 7);
    insert_sorted(&head, 6);
    insert_sorted(&head, 5);
    insert_sorted(&head, 4);
    insert_sorted(&head, 3);
    insert_sorted(&head, 2);
    insert_sorted(&head, 1);
    print_list(&head);
    deallocate(&head);

    return 0;
}

void insert_after(Node *node, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = node->next;
    node->next = new_node;
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

void print_list(Node **head)
{
    Node *curr = *head;
    unsigned int i = 0;
    while(curr != NULL)
    {
        i++;
        printf("elementul %u : %d\n", i, curr->value);
        curr = curr->next;
    }
}

void insert_beginning(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(2);
    new_node->value = new_value;
    new_node->next = *head;
    *head = new_node;
}

void insert_sorted(Node **head, int new_value)
{
    if(*head == NULL || (*head)->value >= new_value)
    {
        insert_beginning(head, new_value);
        return ;
    }

    Node *curr = *head;
    while(curr->next != NULL)
    {
        if(curr->next->value >= new_value)
            break;
        curr = curr->next;
    }
    insert_after(curr, new_value);
}