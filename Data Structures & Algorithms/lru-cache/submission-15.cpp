
struct Node {
    Node* next;
    Node* prev;
    int k;
};


class LRUCache {
public:

    int capacity;
    int size;

    unordered_map<int,int> cache;
    unordered_map<int,Node*> ncache;

    Node* head;
    Node* tail;

    void move_to_front(int key) {
        Node* curr = ncache[key];
        Node* temp = curr->prev;
        curr->prev->next = curr->next;
        curr->next->prev = temp;

        curr->next=  head->next;
        curr->prev = head;
        head->next = curr;
        curr->next->prev = curr;
    }
 
    LRUCache(int capacity) : capacity(capacity) , size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
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

            // evict
            if(size == capacity) {
                Node* evict = tail->prev;
                int eviction_key = evict->k;
                evict->k = key;
                ncache[key] = evict;
                move_to_front(key);

                ncache.erase(eviction_key);
                cache.erase(eviction_key);
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
