class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {
        st = set<int>();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int> > ans;
        int l = -1, r  = -1;
        for(int x: st){
            if(l<0){
                l = r =  x;
            }else if(x == r + 1){
                r = x;
            }else{
                ans.push_back({l, r});
                l = r = x;
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */