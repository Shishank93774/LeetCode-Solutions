//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        vector<int> adj1[n], adj2[n];
        for(int i = 0; i<2*e; i+=2)
            adj1[A[i]].push_back(A[i+1]);
        for(int i = 0; i<2*e; i+=2)
            adj2[B[i]].push_back(B[i+1]);
        
        for(int i = 0; i<n; i++){
            if(adj1[i].size() != adj2[i].size()) return false;
            int l = 0, r = adj1[i].size() - 1;
            while(l<r) if(adj1[i][l++] != adj2[i][r--]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends