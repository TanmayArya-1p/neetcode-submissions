struct Node {
    Node* next;
    Node* prev;
    int k;
};

class LRUCache {
public:

    Node* head;
    Node* tail;
    int capacity;
    int size;

    unordered_map<int, int> cache;
    unordered_map<int, Node*> ncache;

    void move_front(int k) {
        if(cache.find(k) == cache.end()) return;

        Node* curr  = ncache[k];
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        curr->next = head->next;
        curr->prev = head;
        head->next = curr;
        curr->next->prev = curr;
    }


    LRUCache(int capacity) : capacity(capacity) , size(0) {
        if(capacity <= 0) throw invalid_argument("capacity cannot be less than or equal to 0");
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            move_front(key);
            return cache[key];
        }
        return -1;

    }
    
    void put(int key, int value) {

        if(cache.find(key) != cache.end()) {
            cache[key] = value;
            move_front(key);
        } else {
            cache[key] = value;
            // eviction
            if(size == capacity) {
                Node* newnode = tail->prev;
                ncache[key] = newnode;

                cache.erase(newnode->k);   // <--- ADD THIS
                ncache.erase(newnode->k);  // <--- ADD THIS
                newnode->k = key;

                move_front(key);
            } else {
                Node* newnode = new Node();
                newnode->k = key;

                ncache[key] = newnode;
                
                newnode->next = head->next;
                newnode->prev = head;

                head->next = newnode;
                newnode->next->prev =  newnode;
                
                size++;
            }
        }
    }
};
