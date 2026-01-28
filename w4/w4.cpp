#include<iostream>
using namespace std;

class Node
{
public:
    char data;
    Node* parent;
    Node* right;
    Node* left;

    Node();
    Node(char data) : data{ data }, parent{ nullptr }, right{ nullptr }, left{ nullptr } {}
    ~Node() {
        delete right;
        delete left;
    }
    void addright(Node* x) {
        right = x;
        right->parent = this;
        
    }
    void addleft(Node* x) {
        left = x;
        left->parent = this;
    }
};
class Tree {
private:
    Node* root;
public:
    Tree() : root{ nullptr } {}
    ~Tree() { delete root; }
    Node* getroot() { return root; }
    Node* findNode(Node* x, char y) {
        if (x == nullptr) 
            return nullptr;
        if (x->data == y) 
            return x;
        Node* f = findNode(x->left, y);
        if (f) 
            return f;
        return findNode(x->right, y);
    }
    void setTree(char a, char b, char c) {
        if (root == nullptr) {
            root = new Node(a);
        }
        Node* p = findNode(root, a);
        if (b != '.') p->addleft(new Node(b));
        if (c != '.') p->addright(new Node(c));
    }
    void preorder(Node* n) {
        if (n == nullptr) return;
        cout << n->data;
        preorder(n->left);
        preorder(n->right);
    }
    void inorder(Node* n) {
        if (n == nullptr) return;
        inorder(n->left);
        cout << n->data;
        inorder(n->right);
    }
    void postorder(Node* n) {
        if (n == nullptr) return;
        postorder(n->left);
        postorder(n->right);
        cout << n->data;
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        tree.setTree(a, b, c);
    }
    Node* root = tree.getroot();
    tree.preorder(root); cout << endl;
    tree.inorder(root); cout << endl;
    tree.postorder(root); cout << endl;
}