#include <iostream>
#include <stdexcept>
using namespace std;

/* =========================
   Node
   ========================= */
template <typename E>
class Node
{
public:
    E element;
    Node<E> *prev;
    Node<E> *next;

    Node(const E &e) : element(e), prev(nullptr), next(nullptr) {}
};

/* =========================
   Linked List Sequence
   ========================= */
template <typename E>
class LinkedSequence
{
private:
    Node<E> *header;
    Node<E> *trailer;
    int n;

    // rank 위치의 Node 찾기
    Node<E> *getNode(int r) const
    {
        Node<E> *current = header->next;
        for (int i = 0; i < r; i++)
            current = current->next;
        return current;
    }

public:
    LinkedSequence()
    {
        header = new Node<E>(E());
        trailer = new Node<E>(E());
        header->next = trailer;
        trailer->prev = header;
        n = 0;
    }

    ~LinkedSequence()
    {
        Node<E> *current = header->next;
        while (current != trailer)
        {
            Node<E> *temp = current;
            current = current->next;
            delete temp;
        }
        delete header;
        delete trailer;
    }

    /* =========================
       atRank(r) - Node* 반환
       ========================= */
    Node<E> *atRank(int r)
    {
        if (r < 0 || r >= n)
            throw out_of_range("Invalid rank");

        return getNode(r);
    }

    /* =========================
       rankOf(p) - Node*의 rank 반환
       ========================= */
    int rankOf(Node<E> *p)
    {
        Node<E> *current = header->next;
        int rank = 0;

        while (current != trailer)
        {
            if (current == p)
                return rank;
            current = current->next;
            rank++;
        }

        throw runtime_error("Node not found");
    }

    /* =========================
       insertAtRank(r, e)
       ========================= */
    void insertAtRank(int r, const E &e)
    {
        if (r < 0 || r > n)
            throw out_of_range("Invalid rank");

        Node<E> *nextNode;
        if (r == n)
            nextNode = trailer;
        else
            nextNode = getNode(r);

        Node<E> *prevNode = nextNode->prev;
        Node<E> *newNode = new Node<E>(e);

        newNode->next = nextNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        nextNode->prev = newNode;

        n++;
    }

    /* =========================
       insertAfter(p, e)
       ========================= */
    void insertAfter(Node<E> *p, const E &e)
    {
        Node<E> *newNode(e);
        p->next = newNode;
        newNode->prev = p;
    }

    /* =========================
       출력 (확인용)
       ========================= */
    void print() const
    {
        Node<E> *current = header->next;
        int rank = 0;
        while (current != trailer)
        {
            cout << "(" << current->element
                 << ", r=" << rank << ") ";
            current = current->next;
            rank++;
        }
        cout << endl;
    }
};

/* =========================
   사용 예시
   ========================= */
int main()
{
    LinkedSequence<int> seq;

    seq.insertAtRank(0, 10);
    seq.insertAtRank(1, 20);
    seq.insertAtRank(2, 30);
    seq.insertAtRank(3, 40);

    Node<int> *p = seq.atRank(1); // element 20

    seq.insertAfter(p, 25);
    seq.print();
    // (10, r=0) (20, r=1) (25, r=2) (30, r=3) (40, r=4)

    cout << "rankOf(p): " << seq.rankOf(p) << endl;

    return 0;
}