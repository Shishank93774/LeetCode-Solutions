class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 or k+maxPts <=n) return 1.0;
        double windowSum = (n-k+1);
        
        double dp[k];
        for(int i = k-1; i>=0; i--){
            dp[i] = windowSum/maxPts;
            double last = 0;
            if(i+maxPts < k) last = dp[i+maxPts];
            else if(i+maxPts <= n) last = 1.0;
            windowSum += dp[i] - last;
        }
        
        return dp[0];
    }
};