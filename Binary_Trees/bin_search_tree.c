#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    int LeftSize;
    struct Node * left;
    struct Node * right;
} Node;

void insert(Node ** root, int data);
int search(Node ** root, int data);
int findMax(Node * root);
Node * delete(Node * root, int data);


int v[100], k;
void Problema1(Node * root);
void Problema2(Node * root, int k1, int k2);
void Problema3(Node * root, int index);

int main()
{
    Node * root = NULL;
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 17);
    Problema2(root, 8, 19);
    root = delete(root, 20);
    Problema2(root, 8, 19);
    return 0;
}

void Problema1(Node * root)
{
    if (root == NULL)
    {
        printf("\n");
        return;
    }

    Problema1(root -> left);
    printf("%d ", root -> data);
    v[k++] = root -> data;
    Problema1(root -> right);
}

void Problema2(Node * root, int k1, int k2)
{
    if (root == NULL)
    {
        printf("\n");
        return;
    }

    Problema2(root -> left, k1, k2);
    if (root -> data >= k1 && root -> data <= k2)
        printf("%d ", root -> data);
    
    if (root -> data < k2)
    Problema2(root -> right, k1, k2);
}

void Problema3(Node * root, int index)
{
    if (root == NULL)
        return;
    
    if (index == root -> LeftSize)
        printf("%d\n", root -> data);
    else if (index < root -> LeftSize)
        Problema3(root -> left, index);
    else 
        Problema3(root -> right, index - root -> LeftSize - 1);
}

void insert(Node ** root, int data)
{
    if (*root == NULL)
    {
        *root = (Node *) malloc(sizeof(Node));
        (*root) -> data = data;
        (*root) -> left = (*root) -> right = NULL;
        return;       
    }

    if ((*root) -> data >= data)
        insert(&(*root) -> left, data);
    else
        insert(&(*root) -> right, data);
}

int search(Node ** root, int data)
{
    if (*root == NULL)
        return 0;
    
    if ((*root) -> data == data)
        return 1;
    else if ((*root) -> data >= data)
    {
        if ((*root) -> left == NULL)
            return 0;
        else 
            return search(&(*root) -> left, data);
    }
    else
    {
        if ((*root) -> right == NULL)
            return 0;
        else 
            return search(&(*root) -> right, data);
    }
}

int findMax(Node * root)
{
    if (root -> right == NULL)
        return root -> data;
    return findMax(root -> right);
}

Node * delete(Node * root, int data)
{
    if (root == NULL)
        return root;
    
    if (root -> data > data)
        root -> left = delete(root -> left, data);
    else if (root -> data < data)
        root -> right = delete(root -> right, data);
    else
    {
        if (root -> left == NULL)
        {
            Node * tmp = root -> right;
            free(root);
            return tmp;
        }
        else if(root -> right == NULL)
        {
            Node * tmp = root -> left;
            free(root);
            return tmp;
        }
            root -> data = findMax(root -> right);
            root -> right = delete(root -> right, root -> data);
    }
    return root;
}