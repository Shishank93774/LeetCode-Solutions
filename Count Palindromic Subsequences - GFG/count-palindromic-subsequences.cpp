//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod = 1e9+7;
int dp[1001][1001];
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string &str)
    {
       //Your code here
       int n = str.size();
       memset(dp, -1, sizeof dp);
       auto rec = [&](int l, int r, auto &&rec)->int{
           if(l > r) return 0;
           if(l == r) return 1;
           if(dp[l][r] != -1) return dp[l][r];
           int ans = (rec(l+1, r, rec) + rec(l, r-1, rec))%mod;
           if(str[l] == str[r]) ans = (ans + 1)%mod;
           else ans = (ans - rec(l+1, r-1, rec) + mod)%mod;
           
           return dp[l][r] = ans;
       };
       
       return rec(0, n-1, rec);
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends