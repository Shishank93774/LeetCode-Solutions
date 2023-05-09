//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &arr){
        // Code here
        if(n == 1) return 0;
        int pref[n], suf[n];
        pref[0] = arr[0];
        suf[n-1] = arr[n-1];
        for(int i = 1; i<n; i++) pref[i] = max(pref[i-1], arr[i]);
        for(int i = n-2; i>=0; i--) suf[i] = min(suf[i+1], arr[i]);
        int ans = 0;
        for(int i = 1; i<n; i++){
            ans += ((pref[i-1] + suf[i]) >= k);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends