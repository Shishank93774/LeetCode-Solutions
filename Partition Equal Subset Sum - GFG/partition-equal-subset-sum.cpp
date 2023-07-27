//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+n, 0);
        if(sum%2) return false;
        vector<vector<int> > dp(n, vector<int> (2*sum, -1));
        int F = sum/2 + 1;
        auto rec = [&](int i, int sum, auto &&rec)->bool{
            if(i == n){
                return (sum == 0);
            }
            if(dp[i][F+sum] != -1) return dp[i][sum+F];
            
            
           return dp[i][sum+F] = rec(i+1, sum+arr[i], rec) or rec(i+1, sum-arr[i], rec);
           
        };
        return rec(0, 0, rec);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends