//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

int dp[202][202];
class Solution{
	public:
	int minimumCost(int cost[], int n, int W) 
	{ 
        // Your code goes here
        memset(dp, -1, sizeof dp);
        auto rec = [&](int i, int rem, auto &&rec)->int{
            if(rem == 0) return 0;
            if(i == n) return 1e9;
            if(dp[i][rem] != -1) return dp[i][rem];
            int ans = rec(i+1, rem, rec);
            
            if(i+1 <= rem and cost[i] != -1)
                ans = min(ans, cost[i] + rec(i, rem - (i+1), rec));
            
            return dp[i][rem] = ans;
        };
        int ans = rec(0, W, rec);
        return ans==1e9?-1:ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends