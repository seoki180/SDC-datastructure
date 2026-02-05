#include <iostream>
#include <stdexcept>

// template <typename T, int Capacity> // 여러 데이터 타입을 지원하기 위한 템플릿
class ArrayStack
{
private:
    int *arr;     // 배열 포인터
    int top;      // 최상단 인덱스
    int capacity; // 최대 용량

public:
    ArrayStack(int capacity); // 생성자
    ~ArrayStack();            // 소멸자
    void push(const int &x);  // 요소 추가
    int pop();                // 최상단 요소 제거 및 반환
    int peak() const;         // 최상단 요소 확인
    bool empty() const;       // 비어있는지 확인
    int size() const;         // 현재 크기 반환
};

ArrayStack::ArrayStack(int capacity)
{
    this->arr = new int[capacity];
    this->top = -1;
    this->capacity = capacity;
}

ArrayStack::~ArrayStack()
{
    delete[] arr;
}

void ArrayStack::push(const int &x)
{
    this->arr[top + 1] = x;
    top++;
}

int ArrayStack::pop()
{
    if (this->empty())
        throw std::out_of_range("stack is empty");
    int temp = arr[top];
    this->arr[top] = 0;
    top -= 1;
    return temp;
}

int ArrayStack::size() const
{
    return this->top + 1;
}

bool ArrayStack::empty() const
{
    if (top == -1)
        return true;
    return false;
}

int ArrayStack::peak() const
{
    if (this->empty())
        throw std::out_of_range("stack is empty");
    return this->arr[top];
}

int main()
{
    ArrayStack stack(10);
    stack.push(10);
    stack.push(20);
    std::cout << "Top: " << stack.peak() << std::endl;  // 20 출력s
    std::cout << "Pop: " << stack.pop() << std::endl;   // 20 출력
    std::cout << "Size: " << stack.size() << std::endl; // 1 출력
    return 0;
}