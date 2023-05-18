//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        int ans = 0;
        auto dfs = [&](int r, int c, auto &&dfs) ->bool{
            if(r<0 or c<0 or r>=n or c>=m) return false;
            if(matrix[r][c] == 2 or matrix[r][c] == 0) return true;
            matrix[r][c] = 2;
            bool chk = true;
            chk &= dfs(r+1, c, dfs);
            chk &= dfs(r-1, c, dfs);
            chk &= dfs(r, c+1, dfs);
            chk &= dfs(r, c-1, dfs);
            return chk;
        };
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 1 and dfs(i, j, dfs)) ans++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends