#include <iostream>
#include <stdexcept>
using namespace std;

// int main()
// {
//     cout << "hello world";
// }

// class ArrayStack {
// private:
//     int *arr;
//     int top;
//     int capacity;
// public:
//     ArrayStack(int capacity) 
//         {
//             this->capacity = capacity;
//             this->arr = new int[capacity];
//             this->top = -1;
//         };
//     ~ArrayStack() {
//         delete[] arr;
//     }
//     void push(const int &x) {
//         arr[top+1] = x;
//         top += 1;
//     }
//     int pop() {
//         if(!this->empty()) {
//             int a = arr[top];
//             top -= 1;
//             return a;
//         }
//         else {
//             throw out_of_range("");
//         }
//     }
//     int peak() const {
//         if(!this->empty()) {
//             return arr[top];
//         }
//         else {
//             throw out_of_range("");
//         }
//     }
//     bool empty() const {
//         if (top == -1) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
//     int size() const {
//         return top+1;
//     }
// };

// int main() {
//     ArrayStack stack(10);
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     std::cout << "Top: " << stack.peak() << std::endl;
//     std::cout << "Pop: " << stack.pop() << std::endl;
//     std::cout << "Size: " << stack.size() << std::endl;
//     return 0;
// }
// stack은 배열을 통해 구현가능
// Node를 통해서도 구현가능
// queue도 배열과 node를 통해서 구현가능

// struct Node {
//     int data;
//     Node *next;

//     Node(int value) :data(value), next(nullptr) {}
// };

// class LinkedQueue {
// private:
//     Node *front;
//     Node *rear;
//     int currentSize;
// public:
//     LinkedQueue() {
//         currentSize = 0;
//         front = nullptr;
//         rear = nullptr;
//     }
//     ~LinkedQueue();
//     void enqueue(int x) {
//         if(front == nullptr) {
//             Node node(x);
//             front = &node;
//             rear = &node;
//             currentSize++;
//         }
//         else {
//             rear = rear->next;
//             rear->data = x;
//             currentSize++;
//         }
//     }
//     int dequeue() {
//         Node *temp = front;
//         front = nullptr;
//         while(this->rear->next == this->front) {
//             front = rear->next;
//         }
//         currentSize--;
//         return temp->data;
//     }
//     int frontElement() const {
//         return front->data;
//     }
//     int backElement() const {
//         return rear->data;
//     }
//     bool empty() const {
//         return front == nullptr;
//     }
//     int size() const {
//         return currentSize;
//     }
// };