//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1, -1);
        auto rec = [&](int rem, auto &&rec)->int{
            if(rem < 0) return -1e9;
            if(rem == 0) return 0;
            if(dp[rem] != -1) return dp[rem];
            int ans = 1 + max({rec(rem-x, rec), rec(rem-y, rec), rec(rem-z, rec)});
    
            return dp[rem] = ans;
        };
        int ans = rec(n, rec);
        if(ans < 0) ans = 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends