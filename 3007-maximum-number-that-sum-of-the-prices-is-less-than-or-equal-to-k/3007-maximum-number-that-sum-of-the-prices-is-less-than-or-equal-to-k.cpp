#define ll long long
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        ll l = 0, r = 1e17;
        
        auto chk = [&](ll n)->bool{
            ll sum = 0;
            for(int i = x-1; i<=60; i+=x){
                ll blockLen = (1ll<<i)<<1;
                ll cntBlock = n/blockLen;
                ll add = cntBlock*(blockLen>>1);
                ll ex = n%blockLen;
                add += max(0ll, ex - (blockLen>>1));
                sum += add;
            }
            return sum <= k;
        };
        
        while(l<=r){
            ll mid = l + (r - l)/2;
            if(chk(mid)) l = mid + 1;
            else r = mid - 1;
        }
        return l-2;
    }
};