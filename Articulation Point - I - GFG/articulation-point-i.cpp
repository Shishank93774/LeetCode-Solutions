//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> disc(V, 0), low(V);
        vector<bool> AP(V, false);
        int timer = 0;
        auto dfs = [&](int src, int par, auto &&dfs) -> int{
            disc[src] = low[src] = ++timer;
            int conn = 0;
            for(int nbr: adj[src]){
                if(nbr == par) continue;
                if(disc[nbr]){
                    low[src] = min(low[src], disc[nbr]);
                }else{
                    conn++;
                    dfs(nbr, src, dfs);
                    low[src] = min(low[src], low[nbr]);
                    if(disc[src] <= low[nbr]) AP[src] = true;
                }
            }
            return conn;
        };
        vector<int> ans;
        for(int i = 0; i<V; i++) if(!disc[i]) AP[i] = dfs(i, -1, dfs) > 1;
        for(int i = 0; i<V; i++) if(AP[i]) ans.push_back(i);
        if(ans.size() == 0) ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends