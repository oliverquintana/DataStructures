#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class List
{
private:
    Node *head, *tail;
    int len;
public:
    List()
    {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    void AddNodeEnd(int data)
    {
        Node *temp = new Node;
        temp -> value = data;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            tail -> next = NULL;
            temp = NULL;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
            tail -> next = NULL;
        }
        len++;
    }

    void Display()
    {
        Node *temp = new Node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp -> value << endl;
            temp = temp -> next;
        }
    }

    void GetLength()
    {
        cout << len << endl;
    }

    void RemoveNode(int pos)
    {
        Node *temp = new Node;
        temp = head;
        if(pos > len)
        {
            cout << "Index out of range" << endl;
        }
        else if (pos == 0)
        {
            head = temp -> next;
            len--;
        }
        else
        {
            int i = 0;
            while(temp != NULL)
            {
                i++;
                if(temp -> next == tail)
                {
                    temp -> next = NULL;
                    tail = temp;
                    break;
                }
                if(i == pos)
                {
                    Node *temp2 = new Node;
                    temp2 = temp -> next;
                    temp -> next = temp2 -> next;
                    break;
                }
                temp = temp -> next;
            }
            len--;
        }
    }

    void AddNodeStart(int data)
    {
        Node *temp = new Node;
        temp -> value = data;
        temp -> next = head;
        head = temp;
        len++;
    }

    void RemoveNodeLast()
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = new Node;
            Node *temp2 = new Node;
            temp = head;
            int i = 0;
            while(i < len)
            {
                temp2 = temp -> next;
                if (temp2 -> next == NULL)
                {
                    temp -> next = NULL;
                    len--;
                    break;
                }
                temp = temp -> next;
                i++;
            }
        }
    }

    void AddNodePos(int pos, int data)
    {
        if (pos <= len)
        {
            Node *temp = new Node;
            temp = head;
            Node *New = new Node;
            New -> value = data;
            if (pos == 0)
            {
                Node *temp = new Node;
                temp -> value = data;
                temp -> next = head;
                head = temp;
            }
            else
            {
                int i = 1;
                while (i <= len)
                {
                    if(pos == i)
                    {
                        New -> next = temp -> next;
                        temp -> next = New;
                        if (pos == len)
                        {
                            New -> next = NULL;
                            tail = New;
                        }
                        break;
                    }
                    temp = temp -> next;
                    i++;
                }
            }
            len++;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }
};

int main()
{
    List lista;
    lista.AddNodeEnd(1);
    lista.AddNodeEnd(2);
    lista.AddNodeEnd(3);
    lista.AddNodeEnd(4);
    lista.AddNodeEnd(5);
    lista.AddNodeEnd(6);
    lista.AddNodeEnd(7);
    cout << "List:" << endl;
    lista.Display();
    cout << "Length: ";
    lista.GetLength();
    lista.RemoveNode(4);
    cout << "List:" << endl;
    lista.Display();
    cout << "Length: ";
    lista.GetLength();
    lista.AddNodeStart(15);
    cout << "List:" << endl;
    lista.Display();
    cout << "Length: ";
    lista.GetLength();
    lista.RemoveNodeLast();
    cout << "List:" << endl;
    lista.Display();
    cout << "Length: ";
    lista.GetLength();
    lista.AddNodePos(3,30);
    cout << "List:" << endl;
    lista.Display();
    cout << "Length: ";
    lista.GetLength();

    return 0;
}
