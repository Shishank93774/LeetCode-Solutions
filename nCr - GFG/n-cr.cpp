//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[1001][801];
bool chk = false;
const int mod = 1e9+7;
class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(!chk){
            memset(dp, -1, sizeof dp);
            chk = true;
        }
        if(dp[n][r] != -1) return dp[n][r];
        if(n < r) return dp[n][r] = 0;
        if(n == 1) return dp[n][r] = 1;
        if(n == r) return dp[n][r] = 1;
        if(r == 1) return dp[n][r] = n;
        
        dp[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
        dp[n][r] %= mod;
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends