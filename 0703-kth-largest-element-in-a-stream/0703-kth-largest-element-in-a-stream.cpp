class KthLargest {
    priority_queue<int, vector<int>, greater<int> > pqu;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int x: nums) pqu.push(x);
        while(pqu.size() > k) pqu.pop();
        this->k = k;
    }
    
    int add(int val) {
        pqu.push(val);
        if(pqu.size() > k) pqu.pop();
        return pqu.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */