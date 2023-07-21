const int N = 2001;
int dp[N], cnt[N];

class Solution {
    int rec(int i, const vector<int> &arr){
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];
        // Compute
        
        dp[i] = 1;
        cnt[i] = 1;
        for(int j = i-1; j>=0; j--){
            if(arr[i] > arr[j]){
                int t = rec(j, arr) + 1;
                if(dp[i] < t){
                    cnt[i] = cnt[j];
                    dp[i] = t;
                }else if(dp[i] == t){
                    cnt[i] += cnt[j];
                }
            }
        }
        return dp[i];
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<=n; i++) dp[i] = -1, cnt[i] = 0;
        cnt[0] = 1;
        int mx = 1;
        for(int i = n-1; i>=0; i--) mx = max(mx, rec(i, nums));
        int ans = 0;        
        for(int i = 0; i<=n; i++){
            if(dp[i] == mx){
                ans += cnt[i];
            }
        }        
        return ans;
    }
};