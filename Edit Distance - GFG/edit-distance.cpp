//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string &s, string &t) {
        // Code here
        int n = s.size(), m = t.size();
        vector<vector<int> >dp(n+1, vector<int>(m+1, -1));
        
        for(int i = n; i>=0; i--){
            for(int j = m; j>=0; j--){
                if(i == n) dp[i][j] = m-j;
                else if(j == m) dp[i][j] = n-i;
                else{
                    if(s[i] == t[j]) dp[i][j] = dp[i+1][j+1];
                    else{
                        dp[i][j] = 1 + min({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]});
                    }
                }
            }
        }
        
        return dp[0][0];
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