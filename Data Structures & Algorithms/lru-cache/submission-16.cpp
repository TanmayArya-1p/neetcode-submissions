struct Node {
    Node* next;
    Node* prev;
    int k;
};


class LRUCache {
public:
    int capacity;
    int size = 0;
    Node* head;
    Node* tail;

    unordered_map<int,int> cache;
    unordered_map<int,Node*> ncache;


    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    void move_to_front(int key) {
        Node* curr = ncache[key];

        Node* temp = curr->prev;
        curr->prev->next = curr->next;
        curr->next->prev = temp;

        curr->next =  head->next;
        curr->prev = head;
        head->next = curr;
        curr->next->prev = curr;
    }


    int get(int key) {
        if(cache.find(key) != cache.end()) {
            move_to_front(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(get(key) == -1) {
            if(size == capacity) {
                //evict
                Node* evict = tail->prev;
                int evict_key = evict->k;

                move_to_front(evict_key);
                ncache[key] = evict;
                evict->k = key;

                cache.erase(evict_key);
                ncache.erase(evict_key);
            } else {
                size++;

                Node* newnode = new Node();
                newnode->k = key;

                newnode->next = head->next;
                newnode->prev = head;
                head->next = newnode;
                newnode->next->prev = newnode;

                ncache[key] = newnode;
            }
        }
        cache[key] = value;
    }
};
