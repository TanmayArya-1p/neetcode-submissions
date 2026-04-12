#include <bits/stdc++.h>
#include <exception>
#include <list>
#include <stdexcept>
#include <unordered_map>
using namespace std;


template<class T>
struct Node {
    Node* next;
    Node* prev;
    T key;
    Node(int key) : key(key) {
        next = nullptr;
        prev = nullptr;
    }
};

template<class T>
class ListQ {
    public:

    Node<T>* head;
    Node<T>* tail;
    size_t size;
    unordered_map<T, Node<T>*> lookup;
    ListQ() {
        size = 0;
        lookup = {};
        head = nullptr;
        tail = nullptr;
    }

    Node<T>* insert_back(T key) {
        Node<T>* nn = new Node<T>(key);
        size++;
        lookup[nn->key] = nn;
        if(tail == nullptr && head == nullptr) {
            tail = nn;
            head = nn;
            return nn;
        }

        tail->prev = nn;
        nn->next = tail;
        tail = nn;
        return nn;
    }


    T pop_front() {
        if(head == nullptr) {
            throw invalid_argument("queue is empty");
        }

        T temp_k = head->key;
        Node<T>* temp = head;
        if(head->prev != nullptr) {
            head->prev->next = nullptr;
            head = head->prev;
        } else {
            head = nullptr;
            tail = nullptr;
        }

        lookup.erase(temp->key);
        delete temp;
        size--;

        return temp_k;
    }

    void remove(T key) {
        Node<T>* ln = lookup[key];

        if(size == 1) {
            head = nullptr;
            tail = nullptr;
            lookup.erase(key);
            size = 0;
            return;
        }
        size--;

        if(ln->next == nullptr) {
            ln->prev->next = nullptr;
            head = ln->prev;
        } else if(ln->prev == nullptr) {
            ln->next->prev = nullptr;
            tail = ln->next;
        } else {
            ln->next->prev = ln->prev;
            ln->prev->next = ln->next;
        }
        lookup.erase(key);
        delete ln;
    }
};


class LRUCache {
public:
    size_t size;
    size_t capacity;
    unordered_map<int ,pair<int, Node<int>*>> cache;
    ListQ<int> lq;

    LRUCache(int capacity) : capacity(capacity) {
        size = 0;
        lq = {};
    }

    int get(int key) {

        if(cache.find(key) != cache.end()) {
            lq.remove(key);
            Node<int>* nn = lq.insert_back(key);
            cache[key].second = nn;
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {

        bool present = false;
        if(cache.find(key) != cache.end()) {
            lq.remove(key);
            present = true;
        } else if(size == capacity) {
            int remk = lq.pop_front();
            cache.erase(remk);
            size--;
        }

        Node<int>* nn = lq.insert_back(key);
        cache[key] = {value, nn};
        if(!present) size++;
    }
};
