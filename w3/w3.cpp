// #include <iostream>
// #include <vector>   
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int d) {
//         data = d;
//     }
// };

// class DLL {
// private:
//     Node *head;
//     Node *tail;
//     Node *cursor;
//     int size;
// public:
//     DLL() {
//         head = new Node(-1);
//         tail = new Node(-1);
//         cursor = nullptr;
//         size = 0;
//     }
//     void insertNext(Node *position, int data) {
//         Node *newnode = new Node(data);

//         if(size == 0) {
//             head->next = newnode;
//             newnode->prev = head;

//             tail->prev = newnode;
//             newnode->next = tail;
//         }
//         else {
//             Node *n = position->next;

//             position->next = newnode;
//             newnode->prev = position;

//             n->prev = newnode;
//             newnode->next = n;
//         }
//     }
//     void insertFront(Node *position, int data) {
//         Node *newnode = new Node(data);

//         if(size == 0) {
//             Node *n = head;

//             head = newnode;

//             newnode->next = n;
//             n->prev = head;
//         }
//         else {
//             Node *n = position->prev;
//             position->prev = position;

//             n->next = position;
//             position->prev = n;

//             n->prev = position->prev->prev;
            
//         }
//     }
//     void remove(Node *position) {
//         while(cursor == position)
//     }
// };
//집가서 수정하고 실행할 것


#include <iostream>
using namespace std;

struct Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularList {
    private:
    Node *cursor;
    int n;

    public:
    CircularList() 
    : cursor{nullptr}, n{0} {}

    void append(int a) {
        Node *newNode = new Node(a);

        if(cursor == nullptr) {
            this->cursor = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else {
            Node *last = cursor->prev;

            newNode->next = cursor;
            newNode->prev = last;

            last->next = newNode;
            cursor->prev = newNode;


        }
        n++;
    }

    int remove() {
        int data = cursor->data;
        if(n==1) {
            cursor = nullptr;
        }
        else {
            Node *toRemove = cursor;
            Node *preNode = cursor->prev;
            Node *nextNode = cursor->next;

            preNode->next = nextNode;
            nextNode->prev = preNode;
            cursor = nextNode;
        }
        n--;
        return data;
    }

    bool isEmpty() {
        return n==0;
    }

    void move(int k) {
        while(k--) {
            cursor = cursor->next;
        }
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    int n{a};
    CircularList cl;
    for(int i{1}; i <= a; i++) {
        cl.append(i);
    }
    cout << '<';
    while(!cl.isEmpty()) {
        cl.move(b-1);
        cout << cl.remove();
        if(n != 1) {
            cout << ", ";
        }
        n--;
    }
    cout << '>';
}