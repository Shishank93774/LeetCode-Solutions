//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colors(V, -1);
	    auto dfs = [&](int src, int par, int c, auto &&dfs)->bool{
            if(colors[src] != -1) return false;
            colors[src] = c;
    
            for(int nbr: adj[src]){
                if(nbr == par) continue;
                if(colors[nbr] == -1){
                    if(dfs(nbr, par, 1-c, dfs)) return true;
                }else if(colors[nbr] == c) return true;
            }
            return false;
        };
    
        for(int i = 0; i<V; i++){
            if(dfs(i, -1, 0, dfs)) {
                return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends