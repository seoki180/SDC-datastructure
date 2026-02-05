#include <iostream>
#include <stdexcept>
using namespace std;

class Node
{

public:
    int data;   // 저장할 정수 값
    Node *prev; // 이전 노드 포인터
    Node *next; // 다음 노드 포인터

    Node(int e = 0, Node *p = nullptr, Node *n = nullptr)
        : data(e), prev(p), next(n) {}
};

class DLL
{
private:
    Node *header;  // 헤더
    Node *trailer; // 트레일러
    int n;         // 리스트의 크기

public:
    // 생성자
    DLL() : n(0)
    {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }

    // 소멸자
    ~DLL()
    {
        while (!empty())
        {
            removeFront();
        }
        delete header;
        delete trailer;
    }

    // 노드 v 앞에 요소 e를 추가
    void add(Node *v, int e)
    {
        Node *u = new Node(e, v->prev, v);
        v->prev->next = u;
        v->prev = u;
        n++;
    }

    // 노드 v를 제거
    void remove(Node *v)
    {
        Node *u = v->prev;
        Node *w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
        n--;
    }
    // 리스트가 비어있는지 확인
    bool empty() const
    {
        return (n == 0);
    }

    // 리스트의 크기 반환
    int size() const
    {
        return n;
    }

    // 맨 앞 요소 반환
    int front() const
    {
        if (empty())
            throw runtime_error("List is empty");
        return header->next->data;
    }

    // 맨 뒤 요소 반환
    int back() const
    {
        if (empty())
            throw runtime_error("List is empty");
        return trailer->prev->data;
    }

    // 맨 앞에 요소 추가
    void addFront(int e)
    {
        add(header->next, e);
    }

    // 맨 뒤에 요소 추가
    void addBack(int e)
    {
        add(trailer, e);
    }

    // 맨 앞 요소 제거
    void removeFront()
    {
        if (empty())
            throw runtime_error("List is empty");
        remove(header->next);
    }

    // 맨 뒤 요소 제거
    void removeBack()
    {
        if (empty())
            throw runtime_error("List is empty");
        remove(trailer->prev);
    }

    Node *find(int value)
    {
        Node *curr = header->next;
        while (curr != trailer)
        {
            if (curr->data == value)
            {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr; // 찾지 못함
    }
};
