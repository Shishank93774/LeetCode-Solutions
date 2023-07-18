class LNode{
public:
    int key, val;
    LNode *next;
    LNode *prev;
    LNode (){
        key = val = 0;
        next = NULL;
        prev = NULL;
    }
    LNode (int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int sz;
    LNode *head, *tail;
    map<int, LNode*> mp;
    LRUCache(int capacity) {
        sz = capacity;
        head = new LNode(0, 0);
        tail = new LNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(LNode *nd){
        LNode *prevv = nd->prev;
        LNode *nextt = nd->next;
        prevv->next = nextt;
        nextt->prev = prevv;
        mp.erase(nd->key);
        nd->next = nd->prev = NULL;
        delete nd;
    }
    
    void insertNode(LNode *nd){
        nd->next = head->next;
        nd->prev = head;
        head->next->prev = nd;
        head->next = nd;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        LNode *cur = mp[key];
        LNode *newNode = new LNode(key, cur->val);
        deleteNode(cur);
        insertNode(newNode);
        mp[key] = newNode;
        return newNode->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == sz) deleteNode(tail->prev);    
        }else{
            LNode *cur = mp[key];
            deleteNode(cur);
        }
        LNode *newNode = new LNode(key, value);
        insertNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */