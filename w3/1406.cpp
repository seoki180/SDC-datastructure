#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *prev;
    Node *next;

    Node(char data = 0) : data(data), prev(nullptr), next(nullptr) {}
};

class Editor
{
private:
    Node *head;
    Node *tail;
    Node *cursor; // 커서 왼쪽 노드

public:
    Editor()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cursor = head;
    }

    void insert(char c)
    {
        Node *newNode = new Node(c);
        newNode->prev = cursor;
        newNode->next = cursor->next;
        cursor->next->prev = newNode;
        cursor->next = newNode;
        cursor = newNode;
    }

    void moveLeft()
    {
        if (cursor != head)
            cursor = cursor->prev;
    }

    void moveRight()
    {
        if (cursor->next != tail)
            cursor = cursor->next;
    }

    void erase()
    {
        if (cursor == head)
            return;

        Node *toDelete = cursor;
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        cursor = cursor->prev;
        delete toDelete;
    }

    void print()
    {
        Node *cur = head->next;
        while (cur != tail)
        {
            cout << cur->data;
            cur = cur->next;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Editor editor;

    string s;
    cin >> s;
    for (char c : s)
        editor.insert(c);

    int M;
    cin >> M;

    while (M--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
            editor.moveLeft();
        else if (cmd == 'D')
            editor.moveRight();
        else if (cmd == 'B')
            editor.erase();
        else if (cmd == 'P')
        {
            char x;
            cin >> x;
            editor.insert(x);
        }
    }

    editor.print();
    return 0;
}