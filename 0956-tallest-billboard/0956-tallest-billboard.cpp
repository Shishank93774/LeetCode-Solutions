const int LIM = 5001;
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        
        vector<vector<int> > dp(n, vector<int>(2*LIM, -1));
        
        auto rec = [&](int i, int diff, auto &&rec)->int{
            if(i == n) return (diff!=0)*(-1e9);
            
            if(dp[i][diff+LIM] != -1) return dp[i][diff+LIM];
            
            int &ans = dp[i][diff+LIM] = rec(i+1, diff, rec); 
            ans = max({ans, rec(i+1, rods[i] + diff, rec) + rods[i], rods[i] + rec(i+1, diff-rods[i], rec)});
            return ans;
        };
        
        return rec(0, 0, rec)/2;
    }
};