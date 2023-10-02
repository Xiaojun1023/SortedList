
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    head = nullptr;
    curriterpos = nullptr;
    length = 0;
}

template<class T>
SortedList<T>::~SortedList()
{
    MakeEmpty();
}

template<class T>
void SortedList<T>::MakeEmpty() {
    Node* current = head;

    while (current != nullptr)
    {
        head = head->next;
        delete current;
        current = head;
    }

}

template<class T>
bool SortedList<T>::IsFull() const {
    
    try
    {
        NodeT* temp = new NodeT();
        delete temp;
        return false;
    }
    catch (...)
    {
        return true;
    }
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    Node* current = head;
    
    while (current != nullptr)
    {
        if (someItem < current->value)
        {
            return false;
        }

        if (current->value = someItem)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    Node* current = head;
    Node* prev = nullptr;

    if (head == nullptr)
    {
        Node* node = new Node();
        node->value = item;
        node->next = nullptr;
        head = node;
        length++
    }

    while (current != nullptr)
    {
        if (item < current->value)
        {
            Node* node = new Node();
            node->value = item;
            node->next = current;

            if (prev != nullptr)
            {
                prev->next = node;
            }
            else
            {
                head = node;
            }
            length++;
            return;
        }
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        Node* node = new Node();
        node->value = item;
        node->next = nullptr;
        prev->next = node;
        length++;
    }
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (item < current->value)
        {
            return;
        }

        if (current->value == item)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            length--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<class T>
void SortedList<T>::ResetIterator()
{
    curriterpos = nullptr;

}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }

    if (curriterpos != nullptr)
    {
        curriterpos = head;
    }

    T retrunvalue = curriterpos->value;
    curriterpos = curriterpos->next;
}

