auto fast = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();
int dp[46];
auto rec = [](){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i<=45; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return 'c';
}();
class Solution {
public:
    int climbStairs(int n) {
        return dp[n];
    }
};