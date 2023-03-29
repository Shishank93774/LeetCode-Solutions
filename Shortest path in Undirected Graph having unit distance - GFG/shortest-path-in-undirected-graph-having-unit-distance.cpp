//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> dist(N, INT_MAX);
        queue<int> qu;
        qu.push(src);
        vector<int> adj[N];
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int f = qu.front(); qu.pop();
                if(dist[f] != INT_MAX) continue;
                dist[f] = d;
                for(int nbr: adj[f]){
                    if(dist[nbr] == INT_MAX) qu.push(nbr);
                }
            }
            d++;
        }
        for(int i = 0; i<N; i++) dist[i] = (dist[i] == INT_MAX)?-1:dist[i];
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends