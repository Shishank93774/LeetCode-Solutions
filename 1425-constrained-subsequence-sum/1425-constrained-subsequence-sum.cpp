class Solution {
public:
    int constrainedSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int ans = arr[0];
        deque<int> dqu;
        vector<int> dp(n, -1e9);

        for(int i = 0; i<n; i++){
            int ex = (dqu.empty()?0:max(0, dp[dqu.front()]));
            dp[i] = arr[i] + ex;
            ans = max(ans, dp[i]);
            
            while(!dqu.empty() and dp[dqu.back()] <= dp[i]) dqu.pop_back();
            
            dqu.push_back(i);
            if(i - dqu.front() + 1 > k) dqu.pop_front();
            
        }
        return ans;
    }
};