struct Node {
    int key = -1;
    Node* next = nullptr;
    Node* prev = nullptr;
};


class LRUCache {
public:

    int size = 0;
    int capacity;

    Node* head;
    Node* tail;

    unordered_map<int, Node*> ncache;
    unordered_map<int, int> cache;


    LRUCache(int capacity) : capacity(capacity) , head(new Node{}), tail(new Node{}) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(ncache.find(key) != ncache.end()) {
            Node* cnode = ncache[key];
            int ret = cache[key];

            Node* temp = cnode->next;
            cnode->prev->next = temp;
            temp->prev = cnode->prev;

            cnode->next = head->next;
            cnode->prev = head;
            head->next = cnode;
            cnode->next->prev = cnode;

            return ret;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            cache[key] = value;
        } else {

            if(size == capacity) {
                Node* en = tail->prev;
                int evict = tail->prev->key;
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;

                cache.erase(evict);
                ncache.erase(evict);
                size--;
                delete en;
            }


            cache[key] = value;
            Node* nn = new Node{key, nullptr, nullptr};
            nn->prev = head;
            nn->next = head->next;

            head->next = nn;
            nn->next->prev = nn;
            ncache[key] = nn;
            size++;
        }
    }
};
