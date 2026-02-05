#include <iostream>
#include <stdexcept>
using namespace std;

/* =========================
   Position
   ========================= */
template <typename E>
class Position
{
public:
    E element;
    int r; // rank

    Position(const E &e, int rank) : element(e), r(rank) {}
};

/* =========================
   Circular Array Sequence
   (Position을 배열에 저장)
   ========================= */
template <typename E>
class ArraySequence
{
private:
    Position<E> **A; // Position* 를 저장
    int cap;
    int f; // first
    int n; // size

    int index(int r) const
    {
        return (f + r) % cap;
    }

    // rank 전체 재설정 (중요)
    void updateRanks()
    {
        for (int i = 0; i < n; i++)
            A[index(i)]->r = i;
    }

public:
    ArraySequence(int capacity = 5)
        : cap(capacity), f(0), n(0)
    {
        A = new Position<E> *[cap];
    }

    /* =========================
       atRank(r)
       ========================= */
    Position<E> *atRank(int r)
    {
        if (r < 0 || r >= n)
            throw out_of_range("Invalid rank");
        return A[index(r)];
    }

    /* =========================
       rankOf(p)
       ========================= */
    int rankOf(Position<E> *p)
    {
        return p->r;
    }

    /* =========================
       insertAtRank(r, o)
       ========================= */
    void insertAtRank(int r, const E &e)
    {
        if (r < 0 || r > n)
            throw out_of_range("Invalid rank");
        if (n == cap)
            throw overflow_error("Full");

        // 뒤쪽 이동
        // 한칸씩 밀기
        for (int i = n; i > r; i--)
            A[index(i)] = A[index(i - 1)];

        A[index(r)] = new Position<E>(e, r);
        n++;

        updateRanks();
    }

    /* =========================
       insertAfter(p, o)
       ========================= */
    void insertAfter(Position<E> *p, const E &e)
    {
        insertAtRank(rankOf(p) + 1, e);
    }

    /* =========================
       출력 (확인용)
       ========================= */
    void print() const
    {
        for (int i = 0; i < n; i++)
            cout << "(" << A[index(i)]->element
                 << ", r=" << A[index(i)]->r << ") ";
        cout << endl;
    }
};

/* =========================
   사용 예시
   ========================= */
int main()
{
    ArraySequence<int> seq;

    seq.insertAtRank(0, 10);
    seq.insertAtRank(1, 20);
    seq.insertAtRank(2, 30);
    seq.insertAtRank(3, 40);
    // seq.insertAtRank(4, 50);

    Position<int> *p = seq.atRank(1); // element 20

    seq.insertAfter(p, 25);
    seq.print();
    // (10,r=0) (20,r=1) (25,r=2) (30,r=3)

    cout << "rankOf(p): " << seq.rankOf(p) << endl;

    return 0;
}