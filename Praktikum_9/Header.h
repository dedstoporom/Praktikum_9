template <typename T>
class Deque
{
public:

    Deque();
    ~Deque();

    int GetSize() const{ return size_; }
    bool PushFront(const T &data);
    bool PushBack(const T &data);
    bool PopFront();
    bool PopBack();
    
private:

    template <typename>
    class Node
    {
    public:

        Node(T data, Node* pNext = NULL, Node* pPrev = NULL)
        {
            data_ = data;
            pNext_ = pNext;
            pPrev_ = pPrev;
        }

        Node* pNext_;
        Node* pPrev_;
        T data_;
    };

    Node<T>* head_;
    Node<T>* tail_;
    int size_;
};