class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        sort(words.begin(), words.end(), [&](const string &s1, const string &s2){
            return s1.length() < s2.length();
        });
        
        auto pred = [&](const string &pred, const string &cur)->bool{
            if(pred.length() + 1 != cur.length()) return false;
            
            bool skipped = false;
            int i = 0, j = 0, nn = pred.length();
            while(i<nn and j<nn+1){
                if(pred[i] != cur[j]){
                    if(skipped) return false;
                    skipped = true;
                    j++;
                }else{
                    i++; j++;
                }
            }
            return true;
        };
        
        vector<vector<int> > dp(n, vector<int>(n, -1));
        
        auto rec = [&](int i, int prv, auto &&rec)->int{
            if(i == n) return 0;
            if(dp[i][prv+1] != -1) return dp[i][prv+1];
            int a1 = rec(i+1, prv, rec);
            int a2 = 0;
            if(prv == -1 or pred(words[prv], words[i])) a2 = 1 + rec(i+1, i, rec);
            
            return dp[i][prv+1] = max(a1, a2);
        };
        
        return rec(0, -1, rec);
    }
};