class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = abs(n);
        while (nn){
            if (nn & 1)
                ans = ans*x;
            nn = nn>>1;
            x = (x*x);
        }
        if(n < 0) ans = (1.0/ans);
        return ans;
    }
};