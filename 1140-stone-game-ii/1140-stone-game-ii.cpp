const int N = 105;
int dp[N][N][2];

class Solution {
    long long rec(int i, int m, bool ch, const vector<int>& arr){
        if(i >= arr.size()) return 0ll;
        
        if(dp[i][m][ch] != -1) return dp[i][m][ch];
        if(ch){
            long long ans = 0;
            long long lsum = 0;
            for(int x = 0; x<2*m and i+x<arr.size(); x++){
                lsum += arr[i+x];   
                ans = max(ans, lsum+rec(i+x+1, max(m, x+1), !ch, arr));
            }
            return dp[i][m][ch] = ans;
        }else{
            long long ans = INT_MAX;
            for(int x = 0; x<2*m and i+x<arr.size(); x++){
                ans = min(ans, rec(i+x+1, max(m, x+1), !ch, arr));
            }
            return ans;
        }
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, 1, 1, piles);
        return ans;
    }
};