int dp[1001][26][26];
class Solution {
    int rec(int i, char s, char e, vector<string>& arr, int n){
        if(i == n) return 0;
        if(dp[i][s-'a'][e-'a'] != -1) return dp[i][s-'a'][e-'a']; 
        
        int &ans = dp[i][s-'a'][e-'a'] = INT_MAX;
        
        ans = min(ans, (int)arr[i].size() + (e == arr[i][0] ? -1 : 0 ) + rec(i+1, s, arr[i].back(), arr, n) );
        ans = min(ans, (int)arr[i].size() + (s == arr[i].back() ? -1 : 0 )+ rec(i+1, arr[i][0], e, arr, n));
        
        return ans;
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp, -1, sizeof dp);
        return (words[0].size() + rec(1, words[0][0], words[0].back(), words, words.size()));
    }
};