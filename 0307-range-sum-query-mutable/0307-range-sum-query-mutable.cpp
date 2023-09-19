struct Fen{
    vector<int> s;
    int n; 
    Fen(int n): s(n+1, 0), n(n) {}

    void update(int i, int val){
        while(i>0 and i<=n){
            s[i] += val;
            i += (i&(-i));
        }
    }

    int query(int i){
        int ans = 0;
        while(i){
            ans += s[i];
            i -= (i&(-i));
        }
        return ans;
    }

    int query(int l, int r){
        return (query(r) - query(l-1));
    }
};

class NumArray {
    Fen *ft;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        ft = new Fen(n);
        for(int i = 1; i<=n; i++){
            ft->update(i, nums[i-1]);
        }
    }
    
    void update(int index, int val) {
        index++;
        int curval = ft->query(index, index);
        ft->update(index, val-curval);
    }
    
    int sumRange(int left, int right) {
        left++; right++;
        return ft->query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */