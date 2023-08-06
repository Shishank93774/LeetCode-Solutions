class Solution {
public:
    int coinChange(vector<int> &arr, int x) {
        set<int> st(arr.begin(), arr.end());
        
        vector<int> dp(x+1, -1);
        auto rec = [&](int rem, auto &&rec)->int{
            if(rem == 0) return 0;
            
            if(dp[rem] != -1) return dp[rem];
            
            int ans = 1e9;
            for(int x: st){
                if(x > rem) break;
                ans = min(ans, 1 + rec(rem - x, rec));
            }
            return dp[rem] = ans;
        };
        
        int ans = rec(x, rec);
        return ans==1e9?-1:ans;
    }
};