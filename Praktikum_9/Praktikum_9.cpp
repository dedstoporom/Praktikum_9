#include <iostream>
#include "Header.h"
using namespace std;

template <typename T>
Deque<T>::Deque()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}
template <typename T>
Deque<T>:: ~Deque()
{
    while (size_)
        PopFront();
}

template <typename T>
bool Deque<T>::PushFront(const T &data)
{
    head_ = new Node<T>(data, head_, NULL);
    size_++;
    return true;
}
template <typename T>
bool Deque<T>::PushBack(const T &data)
{
    if (head_ == NULL)
    {
        head_ = new Node<T>(data);
        tail_ = head_;
    }
    else
    {
        tail_->pNext_ = new Node<T>(data, NULL, tail_);
        tail_ = tail_->pNext_;
    }

    size_++;
    return true;
}

template <typename T>
bool Deque<T>::PopFront()
{
    if (size_ > 0) {
        Node<T>* temp = head_;
        head_ = head_->pNext_;
        delete temp;
        size_--;
        return true;
    }
    else false;
}

template <typename T>
bool Deque<T>::PopBack()
{
    if (size_ > 0) {

        return true;
    }
    else return false;
}

int main() {
    int action = 0;
    int count;
    Deque<int> dec;
    cout << "Push Back[1]" << endl;
    cout << "Push Front[2]" << endl;
    cout << "PopFront [5]" << endl;
    cout << "Size [3]" << endl;
    cout << "Exit [4]" << endl;
    while (action != 4) {

        cout << "Your action:";
        cin >> action;
        if (action != 4 && action != 3) {
            cout << "Value:";
            cin >> count;
        }
        switch (action)
        {
        case (1): {
            dec.PushBack(count);
            break;
        }
        case (2): {
            dec.PushFront(count);
            break;
        }
        case (3): {
            cout << dec.GetSize() << endl;
            break;
        }
        case (5): {
            cout << dec.PopBack() << endl;
            break;
        }
        }

    }
}

