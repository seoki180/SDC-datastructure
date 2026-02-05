#include <iostream>
#include <stdexcept>

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
        throw std::out_of_range("queue is empty");
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
        throw std::out_of_range("queue is empty");
    }
    return this->front->data;
}

int LinkedQueue::backElement() const
{
    if (this->empty())
    {
        throw std::out_of_range("queue is empty");
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
    LinkedQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Front: " << queue.frontElement() << std::endl; // 10
    std::cout << "Back: " << queue.backElement() << std::endl;   // 30
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;    // 10
    std::cout << "Size: " << queue.size() << std::endl;          // 2
    return 0;
}
