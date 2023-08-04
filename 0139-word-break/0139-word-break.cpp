class Solution {
public:
    bool wordBreak(string &str, vector<string> &wordDict) {
        int n = str.size();
        vector<int> dp(n, -1);
        auto rec = [&](int i, auto &&rec)->bool{
            if(i == n) return true;
            if(dp[i] != -1) return dp[i];
            for(string &word: wordDict){
                if(i + word.size() <= n and (str.substr(i, word.size()) == word)){
                    if(rec(i+word.size(), rec)) return dp[i] = true;
                }
            }
            return dp[i] = false;
        };
        
        return rec(0, rec);
    }
};