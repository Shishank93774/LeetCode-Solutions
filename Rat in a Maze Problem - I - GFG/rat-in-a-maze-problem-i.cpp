//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

int dxy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string dir = "RLDU";

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        vector<string> ans;
        auto dfs = [&](int r, int c, string till, auto &&dfs){
            if(r<0 or c<0 or r>=n or c>=n or arr[r][c] != 1) return;
            if(r == n-1 and c == n-1){
                ans.push_back(till);
                return;
            }
            arr[r][c] = -1;
            for(int i = 0; i<4; i++){
                int tx = r + dxy[i][0], ty = c + dxy[i][1];
                // if(tx<0 or ty<0 or tx>=n or ty>=n or arr[tx][ty] != 1) continue;
                dfs(tx, ty, till+dir[i], dfs);
            }
            arr[r][c] = 1;
        };
        
        dfs(0, 0, "", dfs);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends