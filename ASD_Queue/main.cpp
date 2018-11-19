#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void push(int a, Node *& queue);
int pop(Node *& queue);
int peek(Node * queue);
bool empty(Node * queue);
int search(int a, Node * queue);
void afiseaza(Node * queue);

// Problema 1
void FloodFill(int a[100][100], int i, int j, int k);
void Problema1();

// Problema 2
// 581742963
void Problema2(Node * train_queue);

int main()
{
    Node * train_queue = NULL;
    push(3, train_queue);
    push(6, train_queue);
    push(9, train_queue);
    push(2, train_queue);
    push(4, train_queue);
    push(7, train_queue);
    push(1, train_queue);
    push(8, train_queue);    
    push(5, train_queue);    
    afiseaza(train_queue);
    //Problema2(trains);
}

void FloodFill(int a[100][100], int i, int j, int k)
{
    a[i][j] = k;

    if (a[i + 1][j] == 1) FloodFill(a, i + 1, j, k);
    if (a[i - 1][j] == 1) FloodFill(a, i - 1, j, k);
    if (a[i][j + 1] == 1) FloodFill(a, i, j + 1, k);
    if (a[i][j - 1] == 1) FloodFill(a, i, j - 1, k);
}

void Problema1()
{
    int n, a[100][100], k = 2;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1)
                FloodFill(a, i, j, k++);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

void Problema2(int * trains)
{
    
}

void push(int a, Node *& queue)
{
    if (queue == NULL)
    {
        queue = new Node();
        queue -> data = a;
        queue -> next = NULL;
        
        return;
    }

    Node * iter_queue = queue;

    while (iter_queue -> next)
        iter_queue = iter_queue -> next;

    Node * tmp = new Node();
    tmp -> data = a;
    tmp -> next = NULL;
    iter_queue -> next = tmp;
}

int pop(Node *& queue)
{
    Node * tmp = queue;
    int tmp_data = tmp -> data;
    queue = queue -> next;
    delete tmp;
    return tmp_data;
}

int peek(Node * queue)
{
    return queue -> data;
}

bool empty(Node * queue)
{
    return (queue == NULL)? 1 : 0;
}

int search(int a, Node * queue)
{
    for (int i = 0; queue; i++, queue = queue -> next)
        if (queue -> data == a)
            return i;
    return -1;
}

void afiseaza(Node * queue)
{
    while (queue != NULL)
    {
        printf("%d ", queue -> data);
        queue = queue -> next;
    }
}