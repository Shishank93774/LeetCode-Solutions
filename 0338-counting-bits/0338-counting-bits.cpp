class Solution {
    bool isPowerOfTwo(int x){
        return x && (!(x & (x - 1)));
    }
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n == 1) return {0, 1};
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        int msb = 0;
        for(int i = 2; i<=n; i++){
            if(isPowerOfTwo(i)) msb++;
            dp[i] = 1 + dp[i-(1<<msb)];
        }
        return dp;
    }
};