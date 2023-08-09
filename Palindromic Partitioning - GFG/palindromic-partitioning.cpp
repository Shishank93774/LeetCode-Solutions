//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int pali[501][501];
int dp[501];
class Solution{
    
    bool helper(int l, int r, const string &str){
        if(pali[l][r] != -1) return pali[l][r];
        if(l >= r) return pali[l][r] = true;
        if(l+1 == r) return pali[l][r] = (str[l] == str[r]);
        if(str[l] == str[r]) return pali[l][r] = helper(l+1, r-1, str);
        return pali[l][r] = false;
    }
    
    int rec(int i, const string &str, const int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for(int k = i; k<n; k++){
            if(pali[i][k]){
                ans = min(ans, 1 + rec(k+1, str, n));
            }
        }
        return dp[i] = ans;
    }
    
public:
    int palindromicPartition(const string &str)
    {
        // code here
        int n = str.size();
        memset(pali, -1, sizeof pali);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                helper(i, j, str);
            }
        }
        
        memset(dp, -1, sizeof dp);
        return rec(0, str, n) - 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends