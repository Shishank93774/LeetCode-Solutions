//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int N = 1e3+3;
int dp[N][N];

class Solution {
    int rec(const string &s1, int i, const string &s2, int j){
        if(i == s1.size() or j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j];
        ans = max(rec(s1, i+1, s2, j), rec(s1, i, s2, j+1));
        if(i != j and s1[i] == s2[j]) ans = max(ans, 1 + rec(s1, i+1, s2, j+1));
        return ans;
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    memset(dp, -1, sizeof dp);
		    return rec(str, 0, str, 0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends