#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data) : data(data)
    {
        next = nullptr;
        prev = nullptr;
    }
};

class CircularList
{
private:
    Node *cursor;
    int n;

public:
    CircularList() : cursor(nullptr), n(0) {}
    void append(int a)
    {
        Node *newNode = new Node(a);

        if (cursor == nullptr)
        {
            this->cursor = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *last = cursor->prev;

            newNode->next = cursor;
            newNode->prev = last;
            last->next = newNode;
            cursor->prev = newNode;
        }
        n++;
    }

    int remove()
    {
        int data = cursor->data;
        if (n == 1)
        {
            cursor = nullptr;
        }
        else
        {
            Node *toRemove = cursor;
            Node *prevNode = cursor->prev;
            Node *nextNode = cursor->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            cursor = nextNode;
        }

        n--;
        return data;
    }

    bool isEmpty()
    {
        return n == 0;
    }

    void move(int k)
    {
        while (k--)
            cursor = cursor->next;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;

    CircularList list;
    for (int i = 1; i <= N; i++)
    {
        list.append(i);
    }
    bool first = false;
    cout << "<";
    while (!list.isEmpty())
    {
        list.move(K - 1);
        int removed = list.remove();
        if (first)
        {
            cout << ", ";
        }
        cout << removed;
        first = true;
    }
    cout << ">";
}