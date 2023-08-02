//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string &s, string &t) {
        // Code here
        int n = s.size(), m = t.size();
        vector<vector<int> >dp(n, vector<int>(m, -1));
        auto rec = [&](int i, int j, auto &&rec)->int{
            if(i == n) return (m-j); // all insert
            if(j == m) return (n-i); // all delete
            
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == t[j]) return dp[i][j] = rec(i+1, j+1, rec);
            int a1 = 1 + rec(i+1, j+1, rec); // replace
            int a2 = 1 + rec(i+1, j, rec); // delete
            int a3 = 1 + rec(i, j+1, rec); // insert
            
            return dp[i][j] = min({a1, a2, a3});
        };
        
        return rec(0, 0, rec);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends