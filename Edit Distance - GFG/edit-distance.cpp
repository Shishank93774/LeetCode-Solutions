//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int N = 101;
int dp[N][N];

class Solution {
    int rec(int i, int j, const string &s, const string &t){
        if(i == s.size()) return (t.size() - j);
        if(j == t.size()) return (s.size() - i);
        
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j] = INT_MAX;
        ans = min({ans, 1 + rec(i+1, j+1, s, t), 1 + rec(i, j+1, s, t), 1 + rec(i+1, j, s, t)});
        if(s[i] == t[j]) ans = min(ans, rec(i+1, j+1, s, t));
        return ans;
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        memset(dp, -1, sizeof dp);
        return rec(0, 0, s, t);
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