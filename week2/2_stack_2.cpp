
class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data);
};

class LinkedStack
{
private:
    Node *top;

public:
    LinkedStack();
    ~LinkedStack();
    void push(const int &x);
    int pop();
    int peak();
    int size();
    bool empty();
};
