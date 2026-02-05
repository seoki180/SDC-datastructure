#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    Node *parent;
    Node *left;
    Node *right;

    Node(char data)
    {
        this->data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
private:
    vector<Node *> nodes;
    Node *root;

public:
    Tree()
    {
        this->root = nullptr;
    }

    Node *find(char data)
    {
        for (Node *n : nodes)
        {
            if (n->data == data)
            {
                return n;
            }
        }
        return nullptr;
    }
    Node *getRoot()
    {
        return root;
    }

    void insert(char data)
    {
        Node *node = new Node(data);
        if (root == nullptr)
        {
            this->root = node;
        }
        nodes.push_back(node);
    }

    void setLeft(char p, char c)
    {
        Node *node = this->find(p);
        Node *child = this->find(c);
        node->left = child;
    }
    void setRight(char p, char c)
    {
        Node *node = this->find(p);
        Node *child = this->find(c);
        node->right = child;
    }
};

void preorder(Node *node)
{
    if (!node)
        return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node)
{
    if (!node)
        return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node *node)
{
    if (!node)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Tree *tree = new Tree();
    while (N--)
    {
        char p, l, r;
        cin >> p >> l >> r;
        tree->insert(p);

        if (l != '.')
        {
            if (tree->find(l) == nullptr)
                tree->insert(l);
            tree->setLeft(p, l);
        }
        if (r != '.')
        {
            if (tree->find(r) == nullptr)
                tree->insert(r);
            tree->setRight(p, r);
        }
    }

    Node *root = tree->getRoot();

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}