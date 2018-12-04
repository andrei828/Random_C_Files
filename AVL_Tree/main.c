#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    int height;
    struct Node * right;
    struct Node * left;
} Node;

int get_max_height(int height_1, int height_2)
{
    return (height_1 > height_2)? height_1 : height_2;
}

int height(Node * root)
{
    if (root == NULL)
        return 0;
    return root -> height;
}

int tree_balance(Node * root)
{
    if (root == NULL)
        return 0;
    return height(root -> left) - height(root -> right);
}

Node * build_node(int data)
{
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp -> data = data;
    tmp -> height = 1;
    tmp -> left = tmp -> right = NULL;
    
    return tmp;
}

Node * rotate_right(Node * root)
{
    Node * left_arm = root -> left;
    Node * right_left_arm = left_arm -> right;
    
    left_arm -> right = root;
    root -> left = right_left_arm;
    
    root -> height = get_max_height(height(root -> left), height(root -> right)) + 1;
    left_arm -> height = get_max_height(height(left_arm -> left), height(left_arm -> right)) + 1;
    
    return left_arm;
}

Node * rotate_left(Node * root)
{
    Node * right_arm = root -> right;
    Node * left_right_arm = right_arm -> left;
    
    right_arm -> left = root;
    root -> right = left_right_arm;
    
    root -> height = get_max_height(height(root -> left), height(root -> right)) + 1;
    right_arm -> height = get_max_height(height(right_arm -> left), height(right_arm -> right)) + 1;
    
    return right_arm;
}

Node * add_node(Node * root, int data)
{
    if (root == NULL)
        return build_node(data);
    
    if (data < root -> data)
        root -> left = add_node(root -> left, data);
    else
        root -> right = add_node(root -> right, data);
    
    root -> height = get_max_height(height(root -> left), height(root -> right)) + 1;
    
    if (tree_balance(root) > 1 && data < root -> left -> data)
        return rotate_right(root);
    if (tree_balance(root) < -1 && data > root -> right -> data)
        return rotate_left(root);
    
    if (tree_balance(root) > 1 && data > root -> left -> data)
    {
        root -> left = rotate_left(root -> left);
        return rotate_right(root);
    }
    
    if (tree_balance(root) < -1 && data < root -> right -> data)
    {
        root -> right = rotate_right(root -> right);
        return rotate_left(root);
    }

    return root;
}

char search(Node * root, int data)
{
    if (root == NULL)
	return 0;

    if (root -> data == data)
	    return 1;
    else if (root -> data >= data)
	    return search(root -> left, data);
    else
	    return search(root -> right, data);
}

int maxim(Node * root, int data)
{
    while (root -> right)
        root = root -> right;
    return root -> data;
}

void in_order_traversal(Node * root)
{
    if(root != NULL)
    {
        in_order_traversal(root -> left);
        printf("%d ", root -> data);
        in_order_traversal(root -> right);
    }
}

void read_array(int * n, int ** a)
{
    scanf("%d", n);
    
    *a = (int *) malloc(*n * sizeof(int));
    
    for (int i = 0; i < *n; i++)
        scanf("%d", (*a) + i);
}

int main()
{
    int n, * a;
    Node * root = NULL;
    
    read_array(&n, &a);
    
    for (int i = 0; i < n; i++)
        root = add_node(root, *(a + i));
    
    in_order_traversal(root);

    return 0;
}
