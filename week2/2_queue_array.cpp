#include <iostream>
#include <stdexcept>

class ArrayQueue
{
private:
    int *arr;        // 배열 포인터
    int front;       // 앞 인덱스
    int rear;        // 뒤 인덱스
    int capacity;    // 최대 용량
    int currentSize; // 현재 크기

public:
    ArrayQueue(int capacity); // 생성자
    ~ArrayQueue();            // 소멸자
    void enqueue(int x);      // 후미 추가
    int dequeue();            // 앞 제거 및 반환
    int frontElement() const; // 앞 확인
    int backElement() const;  // 뒤 확인
    bool empty() const;       // 비어있음?
    bool full() const;        // 꽉 참?
    int size() const;         // 현재 크기
};

ArrayQueue::ArrayQueue(int capacity)
{
    this->arr = new int[capacity];
    this->front = 0;
    this->rear = 0;
    this->capacity = capacity;
    this->currentSize = 0;
}

ArrayQueue::~ArrayQueue()
{
    delete[] arr;
}

void ArrayQueue::enqueue(int x)
{
    if (this->full())
    {
        throw std::out_of_range("queue is full");
    }
    this->arr[this->rear] = x;
    this->rear = (this->rear + 1) % this->capacity; // 환형
    this->currentSize++;
}

int ArrayQueue::dequeue()
{
    if (this->empty())
    {
        throw std::out_of_range("queue is empty");
    }
    int temp = this->arr[this->front];
    this->front = (this->front + 1) % this->capacity; // 환형
    this->currentSize--;
    return temp;
}

int ArrayQueue::frontElement() const
{
    if (this->empty())
    {
        throw std::out_of_range("queue is empty");
    }
    return this->arr[this->front];
}

bool ArrayQueue::empty() const
{
    return this->currentSize == 0;
}

bool ArrayQueue::full() const
{
    return this->currentSize == this->capacity;
}

int ArrayQueue::size() const
{
    return this->currentSize;
}

int main()
{
    ArrayQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Front: " << queue.frontElement() << std::endl; // 10
    std::cout << "Back: " << queue.backElement() << std::endl;   // 30
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;    // 10
    std::cout << "Size: " << queue.size() << std::endl;          // 2
    return 0;
}
