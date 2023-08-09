//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int pre[51][51];
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> arr){
        // code here
        
        for(int i = 0; i<=n; i++) pre[i][0] = 0;
        for(int j = 0; j<=m; j++) pre[0][j] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                pre[i][j] = arr[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }    
        
        auto chk = [&](int x)->bool{
            for(int i = 0; i+x<=n; i++){
                for(int j = 0; j+x<=m; j++){
                    int ii = i+x, jj = j+x;
                    if(pre[ii][jj] - pre[ii][j] - pre[i][jj] + pre[i][j] == x*x){
                        return true;
                    }
                }
            }
            return false;
        };
        
        int l = 1, r = min(n, m);
        
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return l-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends