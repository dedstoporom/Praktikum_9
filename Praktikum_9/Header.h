class Deque
{
public:

    Deque();
    ~Deque();

    int GetSize() const { return size_; }
    bool PushFront(const int& data);
    bool PushBack(const int& data);
    bool PopFront();
    bool PopBack();

private:


    class Node
    {
    public:

        Node(int data, Node* pNext = NULL, Node* pPrev = NULL)
        {
            data_ = data;
            pNext_ = pNext;
            pPrev_ = pPrev;
        }

        Node* pNext_;
        Node* pPrev_;
        int data_;
    };

    Node* head_;
    Node* tail_;
    int size_;
};