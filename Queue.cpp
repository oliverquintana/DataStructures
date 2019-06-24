#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class Queue
{
private:
    Node *head, *tail;
public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data)
    {
        Node *temp = new Node;
        temp -> value = data;
        if(head == NULL)
        {
            temp -> next = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            tail -> next = temp;
            temp -> next = NULL;
            tail = temp;
        }
        cout << "Enqueue: " << tail -> value << endl;
    }

    void dequeue()
    {
        if(head == NULL)
        {
            cout << "Empty Queue" << endl;
        }
        else
        {
            cout << "Dequeue: " << head -> value << endl;
            head = head -> next;
        }
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "Empty Queue" << endl;
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            cout << "Queue:" << endl;
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
    Queue cola;
    cola.enqueue(1);
    cola.enqueue(2);
    cola.enqueue(3);
    cola.enqueue(4);
    cola.display();
    cola.dequeue();
    cola.dequeue();
    cola.dequeue();
    cola.dequeue();
    cola.dequeue();
    cola.display();

    return 0;
}
