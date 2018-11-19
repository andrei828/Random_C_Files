#include <stdio.h>
#include <stdlib.h>

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
void rmv(Start * begin, int data);
void display(Start * begin);

int main()
{
    Start * begin = build_list();

    push(begin, 5);
    push(begin, 9);
    display(begin);

    rmv(begin, 12);
    rmv(begin, 5);
    display(begin);
}

Start * build_list()
{
    Start * begin = (Start *) malloc(sizeof(Start));
    begin -> next = NULL;
    return begin;
}

void rmv(Start * begin, int data)
{
    if (begin -> next == NULL)
        return;
    
    Node * iter_list = begin -> next;

    do {
        if (iter_list -> data == data)
        {
            iter_list = iter_list -> prev;
            Node * to_remove = iter_list -> next;
            iter_list -> next = iter_list -> next -> next;
            free(to_remove);
        }
        iter_list = iter_list -> next;
    } while (iter_list != begin -> next);
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

    Node * iter_list = begin -> next;
    while (iter_list -> next != begin -> next)
        iter_list = iter_list -> next;
    
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp -> next = begin -> next;
    tmp -> prev = iter_list;
    tmp -> data = data;
    iter_list -> next = tmp;
}

void display(Start * begin)
{
    Node * iter_list = begin -> next;
    
    do {
        printf("%d ", iter_list -> data);
        iter_list = iter_list -> next;
    } while (iter_list != begin -> next);
    printf("\n");
}