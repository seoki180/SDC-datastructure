
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node* parent;
	char data;
	Node* leftChild;
	Node* rightChild;

	Node(char data) :data(data) {
		parent = nullptr;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	void insertLeft (Node* left) {
		left->parent = this;
		this->leftChild = left;
	}
	void insertRight(Node* right) {
		right->parent = this;
		this->rightChild = right;
	}

};

class Tree {
private:
	Node* root;
	vector<Node*> list;
public:
	Tree(){
		root = nullptr;
	}

	Node* findNode(char data) {
		for (Node* n : list) {
			if (n->data == data)
				return n;
		}
		Node* newNode = new Node(data);
		list.push_back(newNode);

		if (data == 'A') {
			root = newNode;
		}
		return newNode;
	}

	void setNode(char parentData, char left, char right) {
		Node* parent = findNode(parentData);

		if (left != '.') {
			Node* child = findNode(left);
			parent->insertLeft(child);
		}
		if (right != '.') {
			Node* child = findNode(right);
			parent->insertRight(child);
		}
	}

	Node* getRoot() const { return root; }


	void preorder(Node* node) {
		if (!node)
			return;

		cout << node->data;
		preorder(node->leftChild);
		preorder(node->rightChild);
	}
	void inorder(Node* node) {
		if (!node)
			return;

		inorder(node->leftChild);
		cout << node->data;
		inorder(node->rightChild);
	}

	void postorder(Node* node) {
		if (!node)
			return;

		postorder(node->leftChild);
		postorder(node->rightChild);
		cout << node->data;
	}

};

int main() {
	int n;
	char parent, left, right;
	cin >> n;

	Tree tree;
	for (int i = 0; i < n; ++i) {
		cin >> parent >> left >> right;
		tree.setNode(parent, left, right);
	}

	tree.preorder(tree.getRoot()); cout << '\n';
	tree.inorder(tree.getRoot()); cout << '\n';
	tree.postorder(tree.getRoot()); cout << endl;

	return 0;
}