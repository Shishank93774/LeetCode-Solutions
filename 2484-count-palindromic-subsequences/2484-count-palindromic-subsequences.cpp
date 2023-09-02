const int mod = 1e9+7;
class Solution {
    int rev(int n){
        return (10*(n%10) + n/10);
    }
public:
    int countPalindromes(const string &str) {
        int cntF[10] = {0}, cntB[10] = {0}, subF[100] = {0}, subB[100] = {0}, n = str.size();
        for(int i = n-1; i>=0; i--){
            int dig = str[i] - '0';
            
            for(int r = 0; r<=9; r++)
                if(cntB[r])
                    subB[dig*10+r] += cntB[r];
            
            cntB[dig]++;
        }
        
        long long ans = 0;
        
        for(int i = 0; i<n; i++){
            int dig = str[i] - '0';
            
            cntB[dig]--;
            for(int r = 0; r<=9; r++)
                if(cntB[r])
                    subB[dig*10+r] -= cntB[r];
            
            for(int sub = 0; sub<=99; sub++){
                ans += 1ll*subF[sub]*subB[rev(sub)];
                ans %= mod;
            }
            
            for(int l = 0; l<=9; l++)
                if(cntF[l])
                    subF[l*10+dig] += cntF[l];
            cntF[dig]++;
        }
        return ans;
    }
};