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
bool frecv[100];
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
		if (frecv[a[i]] == 0)
		{
			push(a[i], stack);
			frecv[a[i]] = 1;
		}
		else if (empty(stack) == 0 && peek(stack) == a[i])
			pop(stack);
		else 
		{
			cout << "Bad array";
			return;
		}
	} 
	if (empty(stack))
		cout << "Good array";
}

void problema2()
{
	Node * stack = NULL;
	int n;
	char a[100];

	cin >> n;
	for (int i = 0; i < n; i++)
		if (a[i] == 'a')
			push(1, stack);
		else 
			pop(stack);

	if (empty(stack) == 1)
		cout << "Acelasi numar de 'a' si 'b'\n";
	else 
		cout << "Nu e acelasi numar de 'a' si 'b'\n";
}

void paranteze(char * tmp)
{
	Node * stack = NULL;

	for (unsigned int i = 0; tmp[i] != '\0'; i++)
		if (empty(stack) == 1 && tmp[i] == '(')
			push(tmp[i], stack);
		else if(empty(stack) == 1 && tmp[i] == ')')
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