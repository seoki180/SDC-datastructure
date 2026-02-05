#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }
    int lastIndex;
    int root = 1;

    // Bubble Up
    void upHeap(int index)
    {
    }

    void downHeap(int index)
    {
    }

public:
    MinHeap()
    {
        heap.push_back(-1);
        lastIndex = 0;
    }

    void insert(int value)
    {
    }

    int removal()
    {
    }

    bool isEmpty() {}

    int size() {}

    void print()
    {
        int level = 0;
        int count = 0;
        int levelSize = 1; // 현재 레벨의 노드 수 (2^level)

        for (int i = 1; i <= lastIndex; i++)
        {
            cout << heap[i] << " ";
            count++;

            // 현재 레벨의 모든 노드를 출력했으면 줄바꿈
            if (count == levelSize)
            {
                cout << endl;
                count = 0;
                levelSize *= 2;
                level++;
            }
        }

        if (count > 0)
        {
            cout << endl;
        }
    }
};

int main()
{
    MinHeap h;

    // 삽입 테스트
    int data[] = {15, 10, 20, 5, 12, 25, 3};
    for (int v : data)
    {
        cout << "insert(" << v << ")" << endl;
        h.insert(v);
    }

    cout << "\n=== Heap 상태 ===" << endl;
    h.print();

    // 삭제 테스트 (최솟값부터 순서대로 제거)
    cout << "\n=== removal 테스트 ===" << endl;
    for (int i = 0; i < 3; i++)
    {
        int removed = h.removal();
        cout << "removed: " << removed << endl;
    }

    cout << "\n=== 삭제 후 Heap 상태 ===" << endl;
    h.print();

    return 0;
}
