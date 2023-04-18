//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

const int N = 1e3+3;
int dp[N][N];
class Solution
{
    int rec(int i, int j, const string &s1, const string &s2, int n, int m){
        if(i == n or j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j] = max(rec(i+1, j, s1, s2, n, m), rec(i, j+1, s1, s2, n, m));
        if(s1[i] == s2[j]) ans = max(ans, 1 + rec(i+1, j+1, s1, s2, n, m));
        return ans;
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp, -1, sizeof dp);
        return rec(0, 0, s1, s2, x, y);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends