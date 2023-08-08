//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

int dp[5001][2];
bool chk = false;
class Solution{
    const int mod = 1e9+7;
    public:
    long long countWays(int n, int k){
        // code here
        if(n == 1) return k;
        if(k == 1) return (n==2);
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, int prvCnt, auto &&rec)->long long{
            if(i == n) return 1;
            if(dp[i][prvCnt] != -1) return dp[i][prvCnt];
            long long ans = (1ll*(k-1)*rec(i+1, 1, rec))%mod; // change color
            if(prvCnt <= 1)
                ans += rec(i+1, prvCnt+1, rec); // same color
            ans %= mod;
            
            return dp[i][prvCnt] = ans;
        };
        
        return rec(0, 0, rec);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends