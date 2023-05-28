const int N = 1e2 + 2;
int dp[N][N];

class Solution {
    int rec(int l, int r, vector<int> &cuts){
        if(l >= r) return 0;
        if(l+1 == r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        int &ans = dp[l][r] = INT_MAX;
        for(int cut = l+1; cut<r; cut++){
            ans = min(ans, cuts[r] - cuts[l] + rec(l, cut, cuts) + rec(cut, r, cuts));
        }
        return ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof dp);
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return rec(0, cuts.size() - 1, cuts);
    }
};