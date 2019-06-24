#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class Stack
{
private:
    Node *head, *tail;

public:
    Stack()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node;
        temp -> value = data;
        if (head == NULL)
        {
            temp -> next = NULL;
            temp -> prev = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            tail -> next = temp;
            temp -> prev = tail;
            temp -> next = NULL;
            tail = temp;
        }
        cout << "Push: " << temp -> value << endl;
    }

    void pop()
    {
        if(head == NULL)
        {
            cout << "Empty Stack" << endl;
        }
        else if (head == tail)
        {
            cout << "Pop: " << head -> value << endl;
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail -> prev;
            tail -> next = NULL;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Empty Stack" << endl;
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            cout << "Stack: " << endl;
            while(temp != NULL)
            {
                cout << temp -> value << endl;
                temp = temp -> next;
            }
        }
    }
};

int main()
{
    Stack pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.pop();
    pila.display();
    pila.pop();
    pila.display();
    pila.pop();
    pila.display();
    pila.pop();
    pila.display();

    return 0;
}
