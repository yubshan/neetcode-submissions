class LRUCache {
public:

    //Node 
    class Node{
        public: 
            int key; 
            int val;
            Node* prev;
            Node* next;
        Node(int k, int v){
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    //cache
    unordered_map<int, Node*> cache;

    //cache-limit
    int cap = 0;
    
    
    void insertNode(Node* newNode){
        Node* oldNode= head->next;
        head->next = newNode;
        oldNode->prev = newNode;
        newNode->next = oldNode;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        Node* prevNode = oldNode->prev;
        Node* nextNode = oldNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if(cache.count(key) == 0){
            return -1;
        }
        Node* oldNode = cache[key];
        Node* newNode = new Node(oldNode->key, oldNode->val);
        cache.erase(oldNode->key);
        deleteNode(oldNode);
        insertNode(newNode);
        cache[newNode->key] = newNode;
        return newNode->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* oldNode = cache[key];
            deleteNode(oldNode);
            cache.erase(key);
        }
        if(cache.size() == cap){
            Node* oldNode = tail->prev;
            int k = oldNode->key;
            deleteNode(oldNode);
            cache.erase(k);
        }
        Node* newNode = new Node(key, value);
        insertNode(newNode);
        cache[key] = newNode;
    }
};
