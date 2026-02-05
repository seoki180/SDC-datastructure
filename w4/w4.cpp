#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *parent;
    vector<Node *> child;

    Node()
    {
        data = 0;
        parent = NULL;
    }

    Node(int data)
    {
        this->data = data;
        parent = NULL;
    }

    ~Node() {}

    void insertChild(Node *child)
    {
        child->parent = this;
        this->child.push_back(child);
    }

    void delChild(Node *child)
    {
        for (int i = 0; i < this->child.size(); i++)
        {
            if (this->child[i] == child)
            {
                this->child.erase(this->child.begin() + i);
                break;
            }
        }
    }
};

class Tree
{
private:
    Node *root;
    vector<Node *> node_list;

    // 서브트리 삭제용 재귀 함수
    void deleteSubTree(Node *node)
    {
        for (Node *c : node->child)
        {
            deleteSubTree(c);
        }
        delete node;
    }

public:
    Tree()
    {
        root = NULL;
    }

    Tree(int data)
    {
        root = new Node(data);
        node_list.push_back(root);
    }

    ~Tree()
    {
        if (root)
            deleteSubTree(root);
    }

    void setRoot(int data)
    {
        root = new Node(data);
        node_list.push_back(root);
    }

    Node *getRoot()
    {
        return root;
    }

    // data 값으로 노드 찾기
    Node *findNode(int data)
    {
        for (Node *n : node_list)
        {
            if (n->data == data)
                return n;
        }
        return NULL;
    }

    // parent_data를 부모로 하는 노드 삽입
    void insertNode(int parent_data, int data)
    {
        Node *parent = findNode(parent_data);
        if (!parent)
        {
            cout << "Parent not found\n";
            return;
        }

        Node *child = new Node(data);
        parent->insertChild(child);
        node_list.push_back(child);
    }

    // 노드 삭제 (서브트리 전체)
    void delNode(int data)
    {
        Node *target = findNode(data);
        if (!target)
            return;

        // 부모에서 연결 제거
        if (target->parent)
            target->parent->delChild(target);

        // node_list에서 서브트리 노드 제거
        vector<Node *> new_list;
        for (Node *n : node_list)
        {
            Node *cur = n;
            bool is_child = false;
            while (cur)
            {
                if (cur == target)
                {
                    is_child = true;
                    break;
                }
                cur = cur->parent;
            }
            if (!is_child)
                new_list.push_back(n);
        }
        node_list = new_list;

        deleteSubTree(target);
    }

    // 특정 노드의 자식 출력
    void printChild(int data)
    {
        Node *node = findNode(data);
        if (!node)
            return;

        for (Node *c : node->child)
            cout << c->data << " ";
        cout << endl;
    }

    // depth 계산 (root = 0)
    int countdepth(int data)
    {
        Node *node = findNode(data);
        if (!node)
            return -1;

        int depth = 0;
        while (node->parent)
        {
            depth++;
            node = node->parent;
        }
        return depth;
    }

    // preorder 순회
    void preorder(Node *node)
    {
        if (!node)
            return;

        cout << node->data << " ";
        for (Node *c : node->child)
            preorder(c);
    }

    // postorder 순회
    void postorder(Node *node)
    {
        if (!node)
            return;

        for (Node *c : node->child)
            postorder(c);
        cout << node->data << " ";
    }
};