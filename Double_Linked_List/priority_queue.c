#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int priority;
    int data;
    struct Node * next;
} Node;

void push_node(Node ** tmp, int data, int priority);
void remove_node(Node ** tmp, int data);
void display(Node * tmp);

int main()
{
    Node * priority_queue = NULL;
    push_node(&priority_queue, 34, 4);
    push_node(&priority_queue, 89, 2);
    push_node(&priority_queue, 192, 1);
    push_node(&priority_queue, 1294, 3);
    remove_node(&priority_queue, 1294);
    display(priority_queue);
}

void remove_node(Node ** tmp, int data)
{
    if (*tmp == NULL)
        return;

    if ((*tmp) -> data == data)
    {
        Node * to_remove = *tmp;
        *tmp = (*tmp) -> next;
        free(to_remove);
    }
    else
    {
        Node * iter = *tmp;
        while (iter -> next && iter -> next -> data != data)
            iter = iter -> next;
        
        if (iter -> next != NULL)
        {
            Node * to_remove = iter -> next;
            iter -> next = iter -> next -> next;
            free(to_remove);
        }
    }
}

void push_node(Node ** tmp, int data, int priority)
{
    Node * add = (Node *) malloc(sizeof(Node));
    add -> data = data;
    add -> priority = priority;
    add -> next = NULL;

    if (*tmp == NULL)
        *tmp = add;
    else if ((*tmp) -> priority > priority)
    {
        add -> next = *tmp;
        *tmp = add;
    }
    else
    {
        Node * iter = *tmp;
        while (iter -> next && iter -> next -> priority < priority)
            iter = iter -> next;
        
        if (iter -> next == NULL)
            iter -> next = add;
        else
        {
            add -> next = iter -> next;
            iter -> next = add;
        }

    }
}

void display(Node * tmp)
{
    if (tmp == NULL)
        return;
    printf("%d ", (*tmp).data);
    display((*tmp).next);
}