#include <stdlib.h>
#include <stdio.h>

void push_leaf(int * n, int * bin_tree, int data);
void RSD(int n, int * bin_tree, int current_index);
void SRD(int n, int * bin_tree, int current_index);
void SDR(int n, int * bin_tree, int current_index);
void display_inline(int n, int * bin_tree);

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} Node;


void push(Node * root, int data);

int main()
{
    int n = 0;
    int * bin_tree = (int *) malloc(sizeof(int));
    
    push_leaf(&n, bin_tree, 169);    
    push_leaf(&n, bin_tree, 39);    
    push_leaf(&n, bin_tree, 397);    
    push_leaf(&n, bin_tree, 15);
    SRD(n, bin_tree, 0);
    printf("\n");
    display_inline(n, bin_tree); 
}

void push(Node * root, int data)
{
    if (root == NULL)
    {
        root = (Node *) malloc(sizeof(Node));
        root -> data = data;
        root -> left = root -> right = NULL;
        return;
    }

    if (root -> left != NULL)
        push(root -> left);
    else
        push(root -> right);
}

void push_leaf(int * n, int * bin_tree, int data)
{
    if ((*n)++ == 0)
        *bin_tree = data;
    else
    {
        bin_tree = (int *) realloc(bin_tree, *n * sizeof(int));
        if (bin_tree == NULL) 
        {
            printf("Failed to allocate memory\n");
            return;
        }

        bin_tree[*n - 1] = data; 
    }
}

void RSD(int n, int * bin_tree, int current_index)
{
    if (current_index < n)
    {
        int left_child = 2 * current_index + 1;
        int right_child = 2 * current_index + 2;

        printf("%d ", bin_tree[current_index]);

        if (left_child < n)
            SRD(n, bin_tree, left_child);
        
        if (right_child < n)
            SRD(n, bin_tree, right_child);
    }
}

void SRD(int n, int * bin_tree, int current_index)
{
    if (current_index < n)
    {
        int left_child = 2 * current_index + 1;
        int right_child = 2 * current_index + 2;

        if (left_child < n)
            SRD(n, bin_tree, left_child);

        printf("%d ", bin_tree[current_index]);
        
        if (right_child < n)
            SRD(n, bin_tree, right_child);
    }
}

void SDR(int n, int * bin_tree, int current_index)
{
    if (current_index < n)
    {
        int left_child = 2 * current_index + 1;
        int right_child = 2 * current_index + 2;

        if (left_child < n)
            SRD(n, bin_tree, left_child);
        
        if (right_child < n)
            SRD(n, bin_tree, right_child);
        
        printf("%d ", bin_tree[current_index]);
    }
}

void display_inline(int n, int * bin_tree)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(bin_tree + i));
    printf("\n");
}