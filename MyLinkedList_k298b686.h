#ifndef _MY_LINKEDLIST_H_
#define _MY_LINKEDLIST_H_

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename DataType>
class MyLinkedList {
private:
    struct Node {
        DataType data;
        Node* prev;
        Node* next;
        Node(const DataType& d = DataType{}, Node* p = nullptr, Node* n = nullptr)
            : data{d}, prev{p}, next{n} {}
        Node(DataType&& d, Node* p = nullptr, Node* n = nullptr)
            : data{std::move(d)}, prev{p}, next{n} {}
    };

    int theSize;
    Node* head;
    Node* tail;

    void init() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

public:
    class const_iterator {
    protected:
        Node* current;
        const_iterator(Node* p) : current{p} {}
        friend class MyLinkedList<DataType>;
    public:
        const_iterator() : current{nullptr} {}
        const DataType& operator*() const { return current->data; }
        const_iterator& operator++() { current = current->next; return *this; }
        const_iterator operator++(int) { const_iterator old = *this; ++(*this); return old; }
        const_iterator& operator--() { current = current->prev; return *this; }
        const_iterator operator--(int) { const_iterator old = *this; --(*this); return old; }
        bool operator==(const const_iterator& rhs) const { return current == rhs.current; }
        bool operator!=(const const_iterator& rhs) const { return !(*this == rhs); }
    };

    class iterator : public const_iterator {
    protected:
        iterator(Node* p) : const_iterator{p} {}
        friend class MyLinkedList<DataType>;
    public:
        iterator() {}
        DataType& operator*() { return this->current->data; }
        const DataType& operator*() const { return this->current->data; }
        iterator& operator++() { this->current = this->current->next; return *this; }
        iterator operator++(int) { iterator old = *this; ++(*this); return old; }
        iterator& operator--() { this->current = this->current->prev; return *this; }
        iterator operator--(int) { iterator old = *this; --(*this); return old; }
    };

    MyLinkedList() { init(); }

    ~MyLinkedList() {
        clear();
        delete head;
        delete tail;
    }

    MyLinkedList(const MyLinkedList& rhs) {
        init();
        for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
            push_back(*itr);
    }

    MyLinkedList(MyLinkedList&& rhs)
        : theSize(rhs.theSize), head(rhs.head), tail(rhs.tail) {
        rhs.head = nullptr;
        rhs.tail = nullptr;
        rhs.theSize = 0;
    }

    MyLinkedList& operator=(const MyLinkedList& rhs) {
        if (this != &rhs) {
            clear();
            for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
                push_back(*itr);
        }
        return *this;
    }

    MyLinkedList& operator=(MyLinkedList&& rhs) {
        if (this != &rhs) {
            clear();
            delete head;
            delete tail;
            head = rhs.head;
            tail = rhs.tail;
            theSize = rhs.theSize;
            rhs.head = nullptr;
            rhs.tail = nullptr;
            rhs.theSize = 0;
        }
        return *this;
    }

    iterator begin() { return iterator(head->next); }
    const_iterator begin() const { return const_iterator(head->next); }
    iterator end() { return iterator(tail); }
    const_iterator end() const { return const_iterator(tail); }

    int size() const { return theSize; }
    bool empty() const { return theSize == 0; }

    void clear() {
        while (!empty())
            pop_front();
    }

    DataType& front() {
        if (!empty()) return head->next->data;
        throw std::runtime_error("List is empty");
    }

    const DataType& front() const {
        if (!empty()) return head->next->data;
        throw std::runtime_error("List is empty");
    }

    DataType& back() {
        if (!empty()) return tail->prev->data;
        throw std::runtime_error("List is empty");
    }

    const DataType& back() const {
        if (!empty()) return tail->prev->data;
        throw std::runtime_error("List is empty");
    }

    iterator insert(iterator itr, const DataType& x) {
        Node* p = itr.current;
        Node* newNode = new Node(x, p->prev, p);
        p->prev->next = newNode;
        p->prev = newNode;
        ++theSize;
        return iterator(newNode);
    }

    iterator insert(iterator itr, DataType&& x) {
        Node* p = itr.current;
        Node* newNode = new Node(std::move(x), p->prev, p);
        p->prev->next = newNode;
        p->prev = newNode;
        ++theSize;
        return iterator(newNode);
    }

    iterator erase(iterator itr) {
        Node* p = itr.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;
        return retVal;
    }

    iterator erase(iterator from, iterator to) {
        while (from != to)
            from = erase(from);
        return to;
    }

    void push_front(const DataType& x) { insert(begin(), x); }
    void push_front(DataType&& x) { insert(begin(), std::move(x)); }
    void push_back(const DataType& x) { insert(end(), x); }
    void push_back(DataType&& x) { insert(end(), std::move(x)); }

    void pop_front() { erase(begin()); }
    void pop_back() { erase(--end()); }

    void reverseList() {
        if (empty() || theSize == 1) return;
        Node* current = head->next;
        Node* temp = nullptr;
        while (current != tail) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        std::swap(head->next, tail->prev);
        head->next->prev = head;
        tail->prev->next = tail;
    }

    MyLinkedList<DataType>& appendList(MyLinkedList<DataType>&& rlist) {
        if (rlist.empty()) return *this;
        for (iterator itr = rlist.begin(); itr != rlist.end(); ++itr)
            push_back(*itr);
        rlist.clear();
        return *this;
    }

    bool swapAdjElements(iterator& itr) {
        if (itr.current == tail || itr.current->next == tail) return false;
        Node* first = itr.current;
        Node* second = first->next;
        first->next = second->next;
        second->prev = first->prev;
        first->prev->next = second;
        second->next->prev = first;
        second->next = first;
        first->prev = second;
        itr = iterator(second);
        return true;
    }
};

#endif
