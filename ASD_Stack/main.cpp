#include <iostream>

using namespace std;

struct Node {
	int data;
	Node * next;
};

// Stiva problema 1
void push(int a, Node *& stack);
int pop(Node *& stack);
int peek(Node * stack);
bool empty(Node * stack);
int search(int a, Node * stack);
void afiseaza(Node * stack);

// Problema 2
void problema2();

// Paranteze problema 3
void paranteze(char * tmp);

// Circuite problema 4
void problema4();

int main()
{
	//char x[100] = "(()())";
	//paranteze(x);

	problema4();
}

void problema4()
{
	Node * stack = NULL;
	int n, a[100];
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (peek(stack) == a[i])
			pop(stack);
		else 
			push(a[i], stack);
	} 
	if (empty(stack))
		cout << "Good array";
	else 
		cout << "Bad array";
}

void problema2()
{
	Node * stack = NULL;
	int n;
	char a[100];

	cin >> n;
	for (int i = 0; i < n; i++)
		if (a[i] == 'a' && peek(stack) == -1)
			push(1, stack);
		else if (a[i] == 'b' && peek(stack) == -1)
			push(0, stack);
		else if (a[i] == 'a' && peek(stack) == 0)
			pop(stack);
		else if (a[i] == 'a' && peek(stack) == 1)
			push(1, stack);
		else if (a[i] == 'b' && peek(stack) == 1)
			pop(stack);
		else if (a[i] == 'b' && peek(stack) == 0)
			push(0, stack);

	if (empty(stack) == 1)
		cout << "Acelasi numar de 'a' si 'b'\n";
	else 
		cout << "Nu e acelasi numar de 'a' si 'b'\n";
}

void paranteze(char * tmp)
{
	Node * stack = NULL;

	for (unsigned int i = 0; tmp[i] != '\0'; i++)
		if(empty(stack) == 1 && tmp[i] == ')')
		{
			push(tmp[i], stack);
			afiseaza(stack);
			return;
		}
		else if (tmp[i] == ')')
			pop(stack);
		else if (tmp[i] == '(')
			push(tmp[i], stack);

	if (empty(stack) == true)
		cout << "Good stack\n";
	else 
		afiseaza(stack);
}

void push(int a, Node *& stack)
{
	Node * tmp = new Node();
	tmp -> data = a;
	tmp -> next = stack;
	stack = tmp;
}

int pop(Node *& stack)
{
	int tmp = stack -> data;
	Node * to_delete = stack;
	stack = stack -> next;
	delete to_delete;
	return tmp;
}

int peek(Node * stack)
{
	if (stack == NULL)
		return -1;
	return stack -> data;
}

bool empty(Node * stack)
{
	return (stack == NULL)? 1 : 0;
}

int search(int a, Node * stack)
{
	int k = 0;
	while (stack)
	{
		if (stack -> data == a)
			return k;
		k++;
		stack = stack -> next; 
	}
	return -1;
}

void afiseaza(Node * stack)
{
	while (stack)
	{
		cout << (char) stack -> data << ' ';
		stack = stack -> next;
	}
	cout << '\n';
}