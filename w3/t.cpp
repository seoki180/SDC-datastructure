#include <iostream>
using namespace std;

class Node
{
public:
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
    }

    void insert(char c)
    {
    }

    void moveLeft()
    {
    }

    void moveRight()
    {
    }

    void erase()
    {
    }

    void print()
    {
    }
};

int main()
{
}