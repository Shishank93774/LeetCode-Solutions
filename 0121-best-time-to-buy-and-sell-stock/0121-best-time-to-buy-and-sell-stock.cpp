const int N = 1e5+5;
int pse[N], ans, n;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        pse[0] = prices[0];
        for(int i = 1; i<n; i++) pse[i] = min(prices[i], pse[i-1]);       
        ans = INT_MIN;
        for(int i = 0; i<n; i++) ans = max(ans, prices[i] - pse[i]);
        return ans;
    }
};