//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int> > qu;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(c[i][j] == 'W'){
                    qu.push({i, j});
                }
            }
        }
        int cur = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int x, y;
                tie(x, y) = qu.front(); qu.pop();
                if(c[x][y] == 'N') {dist[x][y] = 0; continue;}
                else if(dist[x][y] == INT_MAX) dist[x][y] = 2*cur;
                else continue;
                for(int i = 0; i<4; i++){
                    int tx = x + dx[i], ty = y + dy[i];
                    if(tx<0 or ty<0 or tx>=n or ty>=m or dist[tx][ty] != INT_MAX) continue;
                    qu.push({tx, ty});
                }
            }
            cur++;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(c[i][j] == 'N' or c[i][j] == '.') dist[i][j] = 0;
                else if(dist[i][j] == INT_MAX) dist[i][j] = -1;
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends