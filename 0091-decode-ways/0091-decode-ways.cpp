int dp[101];
class Solution {
    int rec(int i, string str){
        if(i > str.length()) return 0;
        if(i == str.length()) return 1;
        if(str[i] == '0') return 0;
        int ans = 0;
        
        if(dp[i] != -1) return dp[i];
        
        if((str[i] > '2') or (i == str.length()-1)){
            ans += rec(i+1, str);
        }else if(str[i] == '2'){
            if(str[i+1] <= '6'){
                ans += rec(i+1, str) + rec(i+2, str);
            }else{
                ans += rec(i+1, str);
            }
        }else if(str[i] == '1'){
            ans += rec(i+1, str) + rec(i+2, str);
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string str) {
        memset(dp, -1, sizeof(dp));
        return rec(0, str);
    }
};