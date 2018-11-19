#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
};

// adding methods
void push_front(Node *& tmp, int data);
void push_back(Node *& tmp, int data);
void push_pos(Node *&tmp, int data, long pos);
// displaying methods
void display_inline(Node * tmp);
void display_reverse(Node * tmp);
// removing methods
void remove_val(Node *& tmp, int data);
void remove_pos(Node *& tmp, long pos);
// menu method
void display_menu(Node *& linked_list);

int main()
{
    Node * linked_list = NULL;
    display_menu(linked_list);    

}

void display_menu(Node *& linked_list)
{
    while (1)
    {
        cout << "1) Adauga un element la inceput\n";
        cout << "2) Adauga un element la sfarsit\n";
        cout << "3) Adauga un element in interiorul listei\n";
        cout << "4) Afiseaza elmentele in ordine\n";
        cout << "5) Afiseaza elemente in ordine inversa\n";
        cout << "6) Sterge un element dupa numarul de ordine\n";
        cout << "7) Sterge un element dupa valoarea sa\n";
        cout << "8) Inchide programul\n>";

        int n; cin >> n;
        int data;
        long pos;
        switch (n)
        {
            case 1:
                cout << "Numarul:\n>"; cin >> data;
                push_front(linked_list, data);
                break;

            case 2:
                cout << "Numarul:\n>"; cin >> data;
                push_back(linked_list, data);
                break;

            case 3:
                cout << "Numarul:\n>"; cin >> data;
                cout << "Pozitia:/n>"; cin >> pos;
                push_pos(linked_list, data, pos);
                break;

            case 4:
                cout << "Numerele sunt: ";
                display_inline(linked_list);
                cout << "\nApasa orice tasta pentru a continua";
                getchar();
                break;
            
            case 5:
                cout << "Numerele sunt: ";
                display_reverse(linked_list);
                cout << "\nApasa orice tasta pentru a continua";
                getchar();
                break;

            case 6:
                cout << "Pozitia:/n>"; cin >> pos;
                remove_pos(linked_list, pos);
                break;

            case 7:
                cout << "Numarul:/n>"; cin >> data;
                remove_val(linked_list, data);
                break;

            case 8:
                system("exit");
                break;
        } 
        system("clear");
    }
}

void remove_pos(Node *& tmp, long pos)
{
    long k = 0;
    Node * iter = tmp;

    while (iter && k++ < pos)
        iter = iter -> next;
    
    if (iter == NULL)
        return;
    
    Node * to_remove = iter;
    iter = iter -> prev;
    iter -> next = iter -> next -> next;
    iter -> next -> prev = iter;
    delete to_remove;
}

void remove_val(Node *& tmp, int data)
{
    Node * iter = tmp;

    while (iter && iter -> data != data)
        iter = iter -> next;
    
    if (iter == NULL)
        return;
    
    Node * to_remove = iter;
    iter = iter -> prev;
    iter -> next = iter -> next -> next;
    iter -> next -> prev = iter;
    delete to_remove;
}

void display_reverse(Node * tmp)
{
    if (tmp == NULL)
        return;
    display_reverse(tmp -> next);
    cout << tmp -> data << ' ';
}

void display_inline(Node * tmp)
{   
    while (tmp)
    {
        cout << tmp -> data << ' ' ;
        tmp = tmp -> next;
    }
}

void push_pos(Node *&tmp, int data, long pos)
{
    long k = 0;
    while (tmp -> next && k++ < pos)
        tmp = tmp -> next;

    Node * add = new Node();
    add -> data = data;
    add -> next = tmp -> next;
    add -> prev = tmp;

    tmp -> next -> prev = add;
    tmp -> next = add;
}

void push_back(Node *& tmp, int data)
{
    Node * iter = tmp;

    while (iter -> next)
        iter = iter -> next;

    Node * add = new Node();
    add -> data = data;
    add -> next = NULL;
    add -> prev = iter;
    iter -> next = add;
}   

void push_front(Node *& tmp, int data)
{
    Node * add = new Node();
    add -> data = data;
    add -> prev = NULL;
    add -> next = tmp;
    tmp = add;
}