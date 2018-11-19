#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct Start {
    Node * next;
} Start;

Start * build_list();

void push(Start * begin, int data);
void rmv(Start * begin);
void display(Start * begin);

int main()
{
    Start * begin = build_list();

    push(begin, 5);
    push(begin, 9);
    push(begin, 12);
    display(begin);

    rmv(begin);
    display(begin);
}

Start * build_list()
{
    Start * begin = (Start *) malloc(sizeof(Start));
    begin -> next = NULL;
    return begin;
}

void rmv(Start * begin)
{
    if (begin -> next == NULL)
        return;
    
    if (begin -> next -> next == begin -> next)
    { 
        free(begin -> next);
        begin -> next = NULL;
        return;
    }

    Node * to_remove = begin -> next -> prev;
    begin -> next -> prev -> prev -> next = begin -> next;
    begin -> next -> prev = begin -> next -> prev -> prev;
    free(to_remove);
}

void push(Start * begin, int data)
{
    if (begin -> next == NULL)
    {
        begin -> next = (Node *) malloc(sizeof(Node));
        begin -> next -> next = begin -> next;
        begin -> next -> prev = begin -> next;
        begin -> next -> data = data;
        return;
    }
    
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp -> next = begin -> next;
    tmp -> prev = begin -> next -> prev;
    begin -> next -> prev -> next = tmp;
    begin -> next -> prev = tmp;
    tmp -> data = data;
    begin -> next = tmp;
}

void display(Start * begin)
{
    Node * iter_list = begin -> next;
    
    if (iter_list == NULL)
    {
        printf("Empty list\n");
        return;
    }

    do {
        printf("%d ", iter_list -> data);
        iter_list = iter_list -> next;
    } while (iter_list != begin -> next);
    printf("\n");
}