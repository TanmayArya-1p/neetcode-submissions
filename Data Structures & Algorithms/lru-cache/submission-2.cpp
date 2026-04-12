struct Node {
    Node* next;
    Node* prev;
    int key;

    Node(int key) : key(key), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    int size;
    unordered_map<int, pair<int, Node*>> cache;

    Node* popq = nullptr; // LRU (tail)
    Node* addq = nullptr; // MRU (head)

    LRUCache(int capacity) : capacity(capacity), size(0) {}

    void detach(Node* curr) {
        if (!curr) return;

        if (curr->prev) curr->prev->next = curr->next;
        else addq = curr->next;

        if (curr->next) curr->next->prev = curr->prev;
        else popq = curr->prev;

        curr->prev = curr->next = nullptr;
    }

    void push_front(Node* curr) {
        curr->next = addq;
        curr->prev = nullptr;
        if (addq) addq->prev = curr;
        addq = curr;
        if (!popq) popq = curr;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        Node* curr = it->second.second;
        detach(curr);
        push_front(curr);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // UPDATE EXISTING KEY
        if (it != cache.end()) {
            Node* curr = it->second.second;
            detach(curr);
            push_front(curr);
            it->second.first = value;
            return;
        }

        // EVICT ONLY FOR NEW INSERT
        if (size == capacity) {
            Node* curr = popq;
            detach(curr);
            cache.erase(curr->key);
            delete curr;
            size--;
        }

        // INSERT NEW NODE
        Node* nn = new Node(key);
        push_front(nn);
        cache[key] = {value, nn};
        size++;
    }
};
