class SmallestInfiniteSet {
    set<int> adds;
    int cur;
public:
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        if(adds.size() and *adds.begin() < cur){
            int f = *adds.begin();
            adds.erase(adds.begin());
            return f;
        }
        else return cur++;
    }
    
    void addBack(int num) {
        if(cur > num) adds.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */