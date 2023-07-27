class Solution {
public:
    vector<string> removeInvalidParentheses(const string &str) {
        
        int n = str.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        auto rec = [&](int i, int sum, auto &&rec)->int{
            if(sum < 0) return -1e9;
            if(i == n and sum == 0) return 0;
            if(i == n) return -1e9;
            
            if(dp[i][sum] != -1) return dp[i][sum];
            
            int &ans = dp[i][sum] = rec(i+1, sum, rec);
            if(str[i] == '('){
                ans = max(ans, 1 + rec(i+1, sum+1, rec));
            }else if(str[i] == ')'){
                ans = max(ans, 1 + rec(i+1, sum-1, rec));
            }else{
                ans = max(ans, 1 + rec(i+1, sum, rec));
            }
            
            return ans;
        };
        
        int mx = rec(0, 0, rec);
        unordered_set<string> ans;
        auto dfs = [&](int i, int sum, string till, auto &&dfs)->void{
            if(sum<0 or till.size() > mx) return;
            if(i == n){
                if(sum == 0 and till.size() == mx){
                    ans.insert(till);
                }
                return;
            }
            
            dfs(i+1, sum, till, dfs);
            if(str[i] == '('){
                dfs(i+1, sum+1, till+str[i], dfs);
            }else if(str[i] == ')'){
                dfs(i+1, sum-1, till+str[i], dfs);
            }else{
                dfs(i+1, sum, till+str[i], dfs);
            }
        };
        
        dfs(0, 0, "", dfs);
        return vector<string>(ans.begin(), ans.end());
        
    }
};