class Solution {
public:
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = k, r = k;
        int ans = arr[k];
        int mn = arr[k];
        while(l>0 or r+1<n){
            int left = (l-1>=0?arr[l-1]:0);
            int right = (r+1<n?arr[r+1]:0);
            
            if(left <= right){ r++; mn = min(mn, right);}
            else {l--; mn = min(mn, left);}
            
            ans = max(ans, mn*(r - l + 1));
        }
        
        return ans;
        
    }
};