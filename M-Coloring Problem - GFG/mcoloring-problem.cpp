//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(101, -1);
        
        auto dfs = [&](int i, auto &&dfs)->bool{
            if(i == n) return true;
            
            bool ans = false;
            for(int c = 1; c<=m; c++){
                bool chk = true;
                for(int j = 0; j<n; j++){
                    if(!graph[i][j]) continue;
                    if(color[j] == c){
                        chk = false; break;
                    }
                }
                if(chk){
                    color[i] = c;
                    ans = ans or dfs(i+1, dfs);
                    color[i] = -1;
                }
                if(ans) return true;
            }
            return false;
        };
        
        return dfs(0, dfs);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends