#include <iostream>

using namespace std;

struct Node {
	int data;
	static int test;
};

int main()
{
	Node * a = new Node();
	a -> data = 5;
	int Node::test = 28;

	Node * b = new Node();
	cout << b -> data << ' ' << Node::test << '\n';
}
