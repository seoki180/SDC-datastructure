#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <vector>
#include <node.h>
using namespace std;

class Tree
{
private:
    Node *root;
    vector<Node *> node_list;

    void deleteSubTree(Node *node);

public:
    Tree();
    Tree(int data);
    ~Tree();

    void setRoot(int data);
    Node *getRoot();

    void insertNode(int parent_data, int data);
    void delNode(int data);

    Node *findNode(int data);
    void printChild(int data);
    int countdepth(int data);
};

#endif