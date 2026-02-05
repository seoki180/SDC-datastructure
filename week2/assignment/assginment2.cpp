#include <iostream>
#include <stdexcept>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedQueue
{
private:
    Node *front;     // 앞 포인터
    Node *rear;      // 뒤 포인터
    int currentSize; // 현재 크기

public:
    LinkedQueue();            // 생성자
    ~LinkedQueue();           // 소멸자
    void enqueue(int x);      // 후미 추가
    int dequeue();            // 앞 제거 및 반환
    int frontElement() const; // 앞 확인
    int backElement() const;  // 뒤 확인
    bool empty() const;       // 비어있음?
    int size() const;         // 현재 크기
};

LinkedQueue::LinkedQueue()
{
    this->front = nullptr;
    this->rear = nullptr;
    this->currentSize = 0;
}

LinkedQueue::~LinkedQueue()
{
    while (!this->empty())
    {
        this->dequeue();
    }
}

void LinkedQueue::enqueue(int x)
{
    Node *newNode = new Node(x);

    if (this->empty())
    {
        this->front = this->rear = newNode;
    }
    else
    {
        this->rear->next = newNode; // rear 뒤에 연결
        this->rear = newNode;       // rear 이동
    }
    this->currentSize++;
}

int LinkedQueue::dequeue()
{
    if (this->empty())
    {
        return -1;
    }

    Node *temp = this->front;
    int data = temp->data;

    this->front = this->front->next;
    if (this->front == nullptr)
    {
        this->rear = nullptr; // 마지막 요소 삭제
    }
    delete temp;
    this->currentSize--;

    return data;
}

int LinkedQueue::frontElement() const
{
    if (this->empty())
    {
        return -1;
    }
    return this->front->data;
}

int LinkedQueue::backElement() const
{
    if (this->empty())
    {
        return -1;
    }
    return this->rear->data;
}

bool LinkedQueue::empty() const
{
    return this->currentSize == 0;
}

int LinkedQueue::size() const
{
    return this->currentSize;
}

int main()
{
    LinkedQueue *queue = new LinkedQueue();
    int N;
    cin >> N;
    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int x;
            cin >> x;
            queue->enqueue(x);
        }
        else if (cmd == "back")
            cout << queue->backElement() << endl;
        else if (cmd == "size")
            cout << queue->size() << endl;
        else if (cmd == "empty")
            cout << queue->empty() << endl;
        else if (cmd == "pop")
            cout << queue->dequeue() << endl;
        else if (cmd == "front")
            cout << queue->frontElement() << endl;
    }
}


