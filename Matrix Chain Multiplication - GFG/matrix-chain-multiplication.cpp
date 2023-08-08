//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        int dp[100][100];
        memset(dp, -1, sizeof dp);
        auto rec = [&](int l, int r, auto &&rec)->int{
            if(l == r) return 0;
            if(l+1 == r) return arr[l-1]*arr[l]*arr[r];
            
            if(dp[l][r] != -1) return dp[l][r];
            int ans = 1e9;
            for(int k = l; k<r; k++){
                ans = min(ans, arr[l-1]*arr[k]*arr[r] + rec(l, k, rec) + rec(k+1, r, rec));
            }
            
            return dp[l][r] = ans;
        };
        
        return rec(1, n-1, rec);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends