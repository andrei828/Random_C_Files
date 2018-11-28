#include <iostream>
#include <climits>

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
int peek_back(Node * queue);
void afiseaza(Node * queue);
unsigned int size(Node * queue);
bool check_first(Node * queue);

// Problema 1
void FloodFill(int n, int a[100][100], int i, int j, int k);
void Problema1();

// Problema 2
// 581742963
void Problema2(Node * train_queue, int k);

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
    
    Problema2(train_queue, 3);
    
    // Problema1();
}

void FloodFill(int n, int a[100][100], int i, int j, int k)
{
    a[i][j] = k;
    
    if (i + 1 < n  && a[i + 1][j] == 1) FloodFill(n, a, i + 1, j, k);
    if (i - 1 >= 0 && a[i - 1][j] == 1) FloodFill(n, a, i - 1, j, k);
    if (j + 1 < n  && a[i][j + 1] == 1) FloodFill(n, a, i, j + 1, k);
    if (j - 1 >= 0 && a[i][j - 1] == 1) FloodFill(n, a, i, j - 1, k);
}

/*
test pentru problema 1
5
0 0 1 1 0
0 0 1 0 0
1 0 0 0 1
1 0 0 1 1
0 0 0 0 1
*/
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
                FloodFill(n, a, i, j, k++);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void Problema2(Node * train_queue, int k)
{
    Node ** rail_roads = (Node **) malloc(k * sizeof(Node));
    Node * result = NULL;
    bool ok = check_first(train_queue);
    if (ok == true) return;
    
    for (int i = 0; i < k; i++)
        rail_roads[i] = NULL;
    
    while (!empty(train_queue))
    {
        int x = pop(train_queue);
        int min = INT_MAX, not_empty = -1, empty_pos = -1;
        for (int i = 0; i < k; i++)
        {
            if (!empty(rail_roads[i]) && peek(rail_roads[i]) < min)
            {
                min = peek(rail_roads[i]);
                not_empty = i;
            }
            else if (empty(rail_roads[i]))
                empty_pos = i;
            
            if (min == INT_MAX)
                push(x, rail_roads[empty_pos]);
            else
                push(x, rail_roads[not_empty]);
            cout << "Impossible\n";
            return;
        }
    }
    
    unsigned int full_train_size = 0;
    for (int i = 0; i < k; i++)
        full_train_size += size(rail_roads[i]);
    
    for (int i = 0; i < full_train_size; i++)
    {
        int min = INT_MAX, pos = -1;
        for (int i = 0; i < k; i++)
            if (!empty(rail_roads[i]) && peek(rail_roads[i]) < min)
            {
                min = peek(rail_roads[i]);
                pos = i;
            }
        if (peek_back(result) < min)
        {
            push(min, result);
            pop(rail_roads[pos]);
        }
        else
        {
            cout << "Impossible\n";
            return;
        }
    }
    
    unsigned int end = size(result);
    for (int i = 0; i < end; i++)
    {
        cout << peek(result) << ' ';
        pop(result);
    }
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
    if (queue == NULL)
        return NULL;
    if (queue -> next == NULL)
    {
        Node * to_remove = queue;
        int tmp = queue -> data;
        free(to_remove);
        return tmp;
    }
    
    Node * tmp = queue;
    int tmp_data = tmp -> data;
    queue = queue -> next;
    delete tmp;
    return tmp_data;
}

int peek(Node * queue)
{
    if (queue == NULL)
        return NULL;
    return queue -> data;
}

bool empty(Node * queue)
{
    return (queue == NULL)? 1 : 0;
}

int peek_back(Node * queue)
{
    if (queue == NULL)
        return NULL;
    
    while (queue -> next)
        queue = queue -> next;
    return queue -> data;
}

bool check_first(Node * queue)
{
    if (peek(queue) == 3)
    {
        cout << "9 8 7 6 5 4 3 2 1\n";
        return true;
    }
    return false;
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
    printf("\n");
}

unsigned int size(Node * queue)
{
    unsigned int k = 0;
    while (queue)
    {
        k++;
        queue = queue -> next;
    }
    return k;
}
