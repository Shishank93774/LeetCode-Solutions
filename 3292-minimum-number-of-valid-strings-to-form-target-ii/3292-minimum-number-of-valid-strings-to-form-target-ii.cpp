struct segTree{
    vector<int> seg;
    vector<int> arr;
    segTree(const vector<int> &a, int n){
        arr = a;
        seg.resize(4*n + 1);
    }
    void build(int idx, int low, int high){  // O(N)
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(2*idx+1, low, mid);
        build(2*idx+2, mid+1, high);
        {
            seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
        }
    }
    int query(int idx, int low, int high, int l, int r){  //O(logN)
        if(l<= low and high <= r) return seg[idx];
        {
            if(high < l or low > r) {
                return 1e9;
            }
        }
        int mid = low + (high-low)/2;
        int lval = query(2*idx+1, low, mid, l, r);
        int rval = query(2*idx+2, mid +1, high, l, r);
        {
            return min(lval, rval);
        }
    }
    void update(int idx, int low, int high, int i, int val){  // O(logN)
        if(low == high){
            seg[idx] = arr[i] = val;
            return;
        }
        int mid = low + (high - low)/2;
        if(i <= mid){
            update(2*idx+1, low, mid, i, val);
        }else{
            update(2*idx+2, mid+1, high, i, val);
        }
        {
            seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
        }
    }
};

class Solution {
    void zValues(string& s, vector<int> &z) {
        int n = ( int )s.length();
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        return;
    }
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        
        vector<int> reach(n, -1);
        for(string &s: words){
            string temp = s + "$" + target;
            vector<int> z(temp.size());
            zValues(temp, z);
            
            for(int i = 0; i<n; i++){
                reach[i] = max(reach[i], i + z[s.size() + 1 + i]);
            }
        }
        
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        segTree st(dp, n+1);
        st.build(0, 0, n);
        
        for(int i = n-1; i>=0; i--){
            int end = reach[i];
            
            dp[i] = min(dp[i], st.query(0, 0, n, i, end) + 1);
            st.update(0, 0, n, i, dp[i]);
        }
        return dp[0]==1e9?-1:dp[0];
    }
};