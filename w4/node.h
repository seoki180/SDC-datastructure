#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *parent;
    vector<Node *> child;

    Node();
    Node(int data);
    ~Node();

    void insertChild(Node *child);
    void delChild(Node *child);
};

#endif