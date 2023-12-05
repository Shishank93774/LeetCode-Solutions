int dp[201];
class Solution {
public:
    int numberOfMatches(int n) {
        if(n <= 1) return 0;
        if(dp[n]) return dp[n];
        return dp[n] = n%2?numberOfMatches(n-1)+1:numberOfMatches(n/2)+(n/2);
    }
};