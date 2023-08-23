bool isPrime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2 == 0) return false;
    if(n%3 == 0) return false;
    
    for(int i = 5; i*i<=n; i+=6){
        if(n%i == 0) return false;
        if(n%(i+2) == 0) return false;
    }
    return true;
}
int dp[32][2][32];
int rec(int i, bool tight, int cnt, const string &str, int n){
    if(i == n){
        return isPrime(cnt);
    }
    
    int &ans = dp[i][tight][cnt];
    if(ans != -1) return ans;
    ans = 0;
    int ub = (tight?(str[i]-'0'):1);
    
    for(int dig = 0; dig<=ub; dig++){
        ans += rec(i+1, (tight&(dig==ub)), cnt + dig, str, n);
    }
    return ans;
    
}

class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        l--;
        string lstr = bitset<32>(l).to_string();
        string rstr = bitset<32>(r).to_string();
        memset(dp, -1, sizeof dp);
        int lans = rec(0, 1, 0, lstr, lstr.size());
        memset(dp, -1, sizeof dp);
        int rans = rec(0, 1, 0, rstr, rstr.size());
        
        return (rans - lans);
    }
};