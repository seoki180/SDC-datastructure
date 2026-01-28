#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

Node* nodes[26];  // A~Z 노드 저장

void preorder(Node* cur) {
    if (cur == nullptr) return;
    cout << cur->data;
    preorder(cur->left);
    preorder(cur->right);
}

void middleorder(Node* cur) {
    if (cur == nullptr) return;
    middleorder(cur->left);
    cout << cur->data;
    middleorder(cur->right);
}

void postorder(Node* cur) {
    if (cur == nullptr) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->data;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < 26; i++) {
        nodes[i] = new Node(char('A' + i));
    }

    for (int i = 0; i < N; i++) {
        char p, l, r;
        cin >> p >> l >> r;

        Node* parent = nodes[p - 'A'];

        if (l != '.')
            parent->left = nodes[l - 'A'];
        if (r != '.')
            parent->right = nodes[r - 'A'];
    }

    preorder(nodes[0]);
    cout << '\n';
    middleorder(nodes[0]);
    cout << '\n';
    postorder(nodes[0]);

    return 0;
}
