const int mod = 1e9+7;
int dp[1002][1002][2];
int pref[1002][1002][2];


class Solution {
    int LIM;
    int prefix_sum(int z, int o, int prv){
        if(z<0 or o<0) return 0;
        
        int &ans = pref[z][o][prv];
        if(ans != -1) return ans;
        
        ans = rec(z, o, prv) + prefix_sum(z-1, o, prv);
        ans %= mod;
        
        ans += prefix_sum(z, o-1, prv);
        ans %= mod;
        
        ans -= prefix_sum(z-1, o-1, prv);
        ans += mod;
        ans %= mod;
        
        return ans;
    }
    
    int pref_rng(int a, int b, int A, int B, int prv){
        
        int ans = prefix_sum(A, B, prv) - prefix_sum(a-1, B, prv);
        ans += mod;
        ans %= mod;
        
        ans -= prefix_sum(A, b-1, prv);
        ans += mod;
        ans %= mod;
        
        ans += prefix_sum(a-1, b-1, prv);
        ans %= mod;
        
        return ans;
    }
    
    
    int rec(int z, int o, int prv){
        if(z<0 or o<0) return 0;
        
        if(z == 0 and o == 0) return 1;
        
        int &ans = dp[z][o][prv];
        
        if(ans != -1) return ans;
        
        ans = pref_rng(z-(1-prv)*LIM, o-prv*LIM, z-(1-prv), o-prv, (1-prv));
        
        return ans;
    }
public:
    int numberOfStableArrays(int z, int o, int lim) {
        LIM = lim;
        for(int i = 0; i<=z; i++)
            for(int j = 0; j<=o; j++)
                dp[i][j][0] = dp[i][j][1] = pref[i][j][0] = pref[i][j][1] = -1;
        
        int ans = (rec(z, o, 0) + rec(z, o, 1))%mod;
        ans += mod;
        ans %= mod;
        return ans;
    }
};