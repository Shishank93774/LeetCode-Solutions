const int N = (1<<15);
int dp[8][N];

class Solution {
    int rec(int op, int rem, int n, vector<int> &arr){
        if(2*op > n) return 0;
        
        if(dp[op][rem] != -1) return dp[op][rem];
        int &ans = dp[op][rem] = 0;
        for(int i = 0; i<n; i++){
            if((rem&(1<<i))) continue;
            int temp = 0;
            for(int j = i+1; j<n; j++){
                if((rem&(1<<j))) continue;
                temp = max(temp, op*(__gcd(arr[i], arr[j])) + rec(op+1, rem+(1<<i)+(1<<j), n, arr));
            }
            ans = max(ans, temp);
        }
        return ans;
    }
public:
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return rec(1, 0, nums.size(), nums);
    }
};