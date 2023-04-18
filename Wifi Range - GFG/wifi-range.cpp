//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string str, int x){
        // code here
        vector<int> ans(n+1, 0);
        for(int i = 0; i<n; i++) if(str[i] == '1') ans[max(0, i-x)]++, ans[min(n, i+x+1)]--;
        if(ans[0] <= 0) return false;
        for(int i = 1; i<n; i++) {
            ans[i] += ans[i-1];
            if(ans[i] <= 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends