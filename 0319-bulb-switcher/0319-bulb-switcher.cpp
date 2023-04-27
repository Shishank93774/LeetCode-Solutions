class Solution {
public:
    int bulbSwitch(int n) {
        int l = 1, r = n;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(1ll*mid*mid <= n){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l-1;
    }
};