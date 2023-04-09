class Solution {
    long long lcm(long long a, long long b){return a*b/__gcd(a, b);}
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1ll, r = 1e18;
        while(l<=r){
            long long mid = l + (r - l)/2;
            long long cnt = mid/a + mid/b + mid/c;
            cnt = cnt - mid/lcm(a, b) - mid/lcm(b, c) - mid/lcm(a, c);
            cnt += mid/lcm(c, lcm(a, b));
            if(cnt < n) l = mid + 1;
            else r = mid - 1;
        }
        return r + 1;
    }
};