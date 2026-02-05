#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task 구조체
struct Task
{
    string name;
    int priority;
    int duration;

    Task() : name(""), priority(0), duration(0) {}
    Task(string n, int p, int d) : name(n), priority(p), duration(d) {}
};

// w5.cpp의 MinHeap 구조를 Task용으로 확장한 힙
class TaskHeap
{
private:
    vector<Task> heap;
    int lastIndex;
    int root = 1;

    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void upHeap(int index)
    {
        if (index <= root)
            return;
        int p = this->parent(index);
        if (heap[p].priority > heap[index].priority)
        {
            swap(heap[p], heap[index]);
            upHeap(p);
        }
    }

    void downHeap(int index)
    {
        int left = this->leftChild(index);
        int right = this->rightChild(index);

        if (left > lastIndex)
            return;

        int small = left;
        if (right <= lastIndex && heap[right].priority < heap[left].priority)
        {
            small = right;
        }

        if (heap[small].priority < heap[index].priority)
        {
            swap(heap[small], heap[index]);
            downHeap(small);
        }
    }

public:
    TaskHeap()
    {
        heap.push_back(Task()); // index 0: dummy
        lastIndex = 0;
    }

    void insert(Task value)
    {
        heap.push_back(value);
        lastIndex++;
        upHeap(lastIndex);
    }

    Task removal()
    {
        if (lastIndex < root)
            return Task();
        Task minValue = heap[root];
        heap[root] = heap[lastIndex];
        heap.pop_back();
        lastIndex--;

        if (lastIndex >= root)
        {
            downHeap(root);
        }

        return minValue;
    }

    Task peek()
    {
        if (lastIndex < root)
            return Task();
        return heap[root];
    }

    bool isEmpty()
    {
        return lastIndex < root;
    }

    int size()
    {
        return lastIndex;
    }

    void print()
    {
        cout << "현재 대기 중인 작업들:" << endl;
        for (int i = 1; i <= lastIndex; i++)
        {
            cout << "  " << heap[i].name
                 << " (우선순위: " << heap[i].priority
                 << ", 소요시간: " << heap[i].duration << "분)" << endl;
        }
    }
};

// TaskHeap을 내부에 사용하는 우선순위 큐
class TaskPQ
{
private:
    TaskHeap heap;

public:
    void enqueue(Task value)
    {
    }

    Task dequeue()
    {
    }

    Task front()
    {
    }

    bool empty()
    {
    }

    int size()
    {
    }

    void print()
    {
    }
};

int main()
{
    cout << "========================================" << endl;
    cout << "     Task 스케줄러 시뮬레이션" << endl;
    cout << "========================================\n"
         << endl;

    TaskPQ scheduler;

    cout << "=== 작업 추가 ===" << endl;
    scheduler.enqueue(Task("바이러스 검사", 10, 30));
    scheduler.enqueue(Task("이메일 확인", 3, 10));
    scheduler.enqueue(Task("시스템 업데이트", 8, 45));
    scheduler.enqueue(Task("문서 작성", 5, 60));
    scheduler.enqueue(Task("백업", 7, 20));
    scheduler.enqueue(Task("게임", 2, 90));

    scheduler.print();

    cout << "\n=== 다음 실행 작업 ===" << endl;
    scheduler.front();

    cout << "\n=== 모든 작업 실행 ===" << endl;
    while (!scheduler.empty())
    {
        scheduler.dequeue();
    }

    cout << "\n========================================" << endl;

    return 0;
}
