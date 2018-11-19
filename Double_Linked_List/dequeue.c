#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
} Node;

Node ** build_dequeue();

void push_front(Node ** front_p, int data);
void push_back(Node ** back_p, int data);
void pop_front(Node ** front_p);
void pop_back(Node ** back_p);
void display(Node * front_p);

int main()
{
    Node ** dequeue = build_dequeue();
    push_front(&dequeue[0], 4);
    push_front(&dequeue[0], 8);
    push_front(&dequeue[0], 21);
    push_front(&dequeue[0], 76);
    display(dequeue[0]);
}

Node ** build_dequeue()
{
    Node ** dequeue = (Node **) malloc(2 * sizeof(Node *));
    dequeue[0] = (Node *) malloc(sizeof(Node));
    dequeue[0] -> next = NULL;
    dequeue[0] -> prev = NULL;
    dequeue[0] -> data = -1;
    dequeue[1] = dequeue[0];
    return dequeue;
}

void display(Node * front_p)
{
    if (front_p)
    {
        printf("%d ", front_p -> data);
        display(front_p -> next);
    }
}

void push_front(Node ** front_p, int data)
{
    if ((*front_p) -> data == -1)
    {
        (*front_p) -> data = data;
        return;
    }

    Node * add = (Node *) malloc(sizeof(Node));
    add -> data = data;
    add -> next = *front_p;
    add -> prev = NULL;
    *front_p = add;
}

void push_back(Node ** back_p, int data)
{
    if ((*back_p) -> data == -1)
    {
        (*back_p) -> data = data;
        return;
    }

    Node * add = (Node *) malloc(sizeof(Node));
    add -> data = data;
    add -> next = NULL;
    add -> prev = *back_p;
    *back_p = add;
}

void pop_front(Node ** front_p)
{
    if (*front_p == NULL)
        return;

    Node * to_remove = *front_p;
    *front_p = (*front_p) -> next;
    free(to_remove);
}

void pop_back(Node **  back_p)
{
    if (*back_p == NULL)
        return;

    Node * to_remove = *back_p;
    (*back_p) = (*back_p) -> prev;
    free(to_remove);
}