#define ll long long
ll dp[16][2][2];
class Solution {
    ll rec(int i, bool tlo, bool thi, const string &lo, const string &hi, const string &suff, int n, int lim){
        if(i == n) return 1ll;
        
        ll &ans = dp[i][tlo][thi];
        if(ans != -1) return ans;
        ans = 0ll;
        
        int lb = 0, ub = 9;
        if(tlo) lb = lo[i] - '0';
        if(thi) ub = hi[i] - '0';
        ub = min(ub, lim);
        
        for(int dig = lb; dig <= ub; dig++){
            int ntlo = tlo, nthi = thi;
            if(dig != lo[i] - '0') ntlo = false;
            if(dig != hi[i] - '0') nthi = false;
            
            if(i+suff.size() >= n){
                int d = n - i;
                if(dig != suff[suff.size() - d] - '0') continue;
                ans += rec(i+1, ntlo, nthi, lo, hi, suff, n, lim);
            }else{
                ans += rec(i+1, ntlo, nthi, lo, hi, suff, n, lim);
            }
            
        }
        return ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int lim, string suff) {
        string lo = to_string(start), hi = to_string(finish);
        
        reverse(lo.begin(), lo.end());
        while(lo.size() < hi.size()) lo.push_back('0');
        reverse(lo.begin(), lo.end());
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 1, lo, hi, suff, hi.size(), lim);
    }
};