short dp[101][101];

class Solution {
    bool rec(int i, int sum, const string &str, int n){
        if(sum < 0) return false;
        if(i == n) return (sum == 0);
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        short &ans = dp[i][sum] = 0;
        
        if(str[i] == '('){
            ans = rec(i+1, sum+1, str, n);
        }else if(str[i] == ')'){
            ans = rec(i+1, sum-1, str, n);
        }else{
            ans = (rec(i+1, sum, str, n) or rec(i+1, sum+1, str, n) or rec(i+1, sum-1, str, n));
        }
        return ans;
    }
public:
    bool checkValidString(string &str) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, str, str.size());
    }
};