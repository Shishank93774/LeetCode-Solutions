//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define tt first
#define ff second

const int mod = 1e3+3;

const int N = 2e2+2;
pair<int, int> dp[N][N];
class Solution{
public:
    int countWays(int n, string &str){
        // code here
        for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) dp[i][j] = {-1, -1};
        auto rec = [&](int l, int r, auto &&rec)->pair<int, int>{
            if(l == r){
                if(str[l] == 'T') return {1, 0};
                return {0, 1};
            }
            if(dp[l][r].tt != -1) return dp[l][r];
            pair<int, int> ans = {0, 0};
            
            for(int k = l+1; k<r; k+=2){
                auto lh = rec(l, k-1, rec);
                auto rh = rec(k+1, r, rec);
                if(str[k] == '|'){
                    ans.tt = (ans.tt + lh.tt*(rh.tt + rh.ff) + rh.tt*lh.ff)%mod;
                    ans.ff = (ans.ff + lh.ff*rh.ff)%mod;
                }else if(str[k] == '&'){
                    ans.tt = (ans.tt + lh.tt*rh.tt)%mod;
                    ans.ff = (ans.ff + lh.ff*(rh.tt + rh.ff) + rh.ff*lh.tt)%mod;
                }else{
                    ans.tt = (ans.tt + lh.tt*rh.ff + lh.ff*rh.tt)%mod;
                    ans.ff = (ans.ff + lh.tt*rh.tt + lh.ff*rh.ff)%mod;
                }
            }
            
            return dp[l][r] = ans;
        };
        
        return rec(0, n-1, rec).first;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends