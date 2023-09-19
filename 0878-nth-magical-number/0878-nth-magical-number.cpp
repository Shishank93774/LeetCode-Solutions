const int mod = 1e9+7;
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 0, r = 1e14;
        
        int L = lcm(a, b);
        
        while(l<=r){
            long long mid = l + (r - l)/2;
            
            if(mid/a + mid/b - mid/L < n) l = mid + 1;
            else r = mid - 1;
        }
        
        return (r+1)%mod;
        
    }
};