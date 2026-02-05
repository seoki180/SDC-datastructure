#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

class SLL
{
private:
    Node *head;
    Node *tail;

public:
    SLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void add(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
            return;
        }
        this->tail->next = node;
        this->tail = node;
    }

    void insert(Node *node)
    {
    }
};

int main()
{
}