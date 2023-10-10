class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        set<int> st(arr.begin(), arr.end());
        vector<int> tmp(st.begin(), st.end());
        int ans = n-1, len = tmp.size();
        int l = 0, r = 0;
        while(l<len and r<len){
            int lhs = tmp[l];
            int rhs = tmp[l] + n - 1;
            while(r<len and tmp[r] <= rhs) r++;
            ans = min(ans, n - (r - l));
            l++;
        }
        
        return ans;
    }
};