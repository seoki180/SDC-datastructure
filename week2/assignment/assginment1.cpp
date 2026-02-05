#include <iostream>
#include <stdexcept>
using namespace std;

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
        return -1;
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
        return -1;
    return this->arr[top];
}

int main()
{
    ArrayStack stack(10000);
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
            stack.push(x);
        }
        else if (cmd == "top")
            cout << stack.peak() << endl;
        else if (cmd == "size")
            cout << stack.size() << endl;
        else if (cmd == "empty")
            cout << stack.empty() << endl;
        else if (cmd == "pop")
            cout << stack.pop() << endl;
    }
}