class Solution {
    bool chk(long x, int i, int sum, int n){
        long lsum = x*(x-1)/2;
        if(x <= i+1) lsum += 1*(i+1 - x);
        else lsum -= (x-i)*(x-i-1)/2;
        long rsum = x*(x-1)/2;
        if(x+i-1 <= n) rsum += 1*(n-x-i);
        else rsum -= (x+i-n)*(x+i-n+1)/2;
        return sum >= (lsum + x + rsum);
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum - n + 1;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid, index, maxSum, n)) l = mid + 1;
            else r = mid - 1;
        }
        return l-1;
    }
};