const int N = 2004 + 4;
int dp[N][N];
class Solution {
    int rec(int i, int k, vector<vector<int> > &piles, vector<int> &rems, int n){
        if(i == n) return (k?INT_MIN:0);
        if(k == 0) return 0;
        if(rems[i] < k) return 0;
        if(dp[i][k] > 0) return dp[i][k];
        int a1 = rec(i+1, k, piles, rems, n);
        int pref = 0;
        int a2 = 0;
        for(int take = 1; take <= piles[i].size() and take <= k; take++){
            pref += piles[i][take-1];
            int t = pref + rec(i+1, k-take, piles, rems, n);
            a2 = max(a2, t);
        }
        return dp[i][k] = max(a1, a2);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof dp);
        int n = piles.size();
        vector<int> rems(n);
        rems[n-1] = piles[n-1].size();
        for(int i = n-2; i>=0; i--) rems[i] = rems[i+1] + piles[i].size();
        return rec(0, k, piles, rems, n);
    }
};