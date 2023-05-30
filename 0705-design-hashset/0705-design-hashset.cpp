class MyHashSet {
    bool has[1000006];
public:
    void add(int key) {has[key] = true;}
    
    void remove(int key) {has[key] = false;}
    
    bool contains(int key) {return has[key];}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */