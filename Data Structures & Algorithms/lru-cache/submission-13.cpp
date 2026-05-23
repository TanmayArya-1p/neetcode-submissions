
struct Node {
    Node* next;
    Node* prev;
    int k;
};


void delete_node(Node* curr) {
    Node* prev = curr->prev;
    Node* nxt = curr->next;

    prev->next = nxt;
    if(nxt != nullptr) {
        nxt->prev = prev;
    }
}

void insert_front(Node* head , Node* curr) {

    Node* temp = head->next;

    head->next = curr;
    curr->prev = head;
    curr->next = temp;

    if(temp != nullptr) {
        temp->prev = curr;
    }
}


class LRUCache {
public:

    Node* head;
    Node* last;

    unordered_map<int, int> cache;
    unordered_map<int, Node*> ncache;


    int capacity;
    int size;

    LRUCache(int capacity) : capacity(capacity) , size(0) {
        head = new Node();
        head->k = -1;

        last = head;
    }
    
    int get(int key) {
        for(auto &[k, _] : cache) cout << k << " ";
        cout << last->k << endl;
        cout << endl;

        if(cache.find(key) != cache.end()) {
            // mvoe it the front
            Node* curr = ncache[key];
            if(curr == last) {
                last = curr->prev;
            }
            delete_node(curr);
            insert_front(this->head, curr);
            if(size == 1) last = curr;

            return cache[key];
        } else {
            return -1;
        } 
    }
    

    void put(int key, int value) {
        for(auto &[k, _] : cache) cout << k << " ";
        cout << last->k << endl;
        cout << endl;

        Node* knode = nullptr;
        if(ncache.find(key) != ncache.end()) {
            knode = ncache[key];
            if(knode == last) last = last->prev;
            delete_node(knode);
        }

        if(knode == nullptr) {
            if(size == capacity) {
                delete_node(last);
                Node* temp = last;
                last = last->prev;

                if(temp != nullptr) {
                    cache.erase(temp->k);
                    ncache.erase(temp->k);
                    delete temp;
                }
                size--;
            }
            size++;
            knode = new Node();
            knode->k = key;
        }

        if(size == 1) last = knode;

        cache[key] = value;
        ncache[key] = knode;

        insert_front(this->head, knode);
    }
};
