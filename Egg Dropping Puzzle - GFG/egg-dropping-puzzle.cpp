//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int> >dp(n+1, vector<int>(k+1, -1));
        auto rec = [&](int eggLeft, int floorsLeft, auto &&rec)->int{
            if(floorsLeft == 0) return 0;
            if(floorsLeft == 1) return 1;
            if(eggLeft == 0) return 0;
            if(eggLeft == 1) return floorsLeft;
            
            if(dp[eggLeft][floorsLeft] != -1) return dp[eggLeft][floorsLeft];
            
            int ans = 1e9;
            
            for(int throws = 1; throws<=floorsLeft; throws++){
                ans = min(ans, 1 + max(rec(eggLeft, floorsLeft-throws, rec) , rec(eggLeft-1, throws-1, rec)));
            }
            return dp[eggLeft][floorsLeft] = ans;
        };
        
        return rec(n, k, rec);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends