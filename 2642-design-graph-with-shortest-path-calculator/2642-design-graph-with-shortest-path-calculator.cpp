class Graph {
    vector<vector<int> > gf;
    int V;
public:
    Graph(int n, vector<vector<int>>& edges) {
        V = n;
        gf = vector<vector<int> >(n, vector<int>(n, INT_MAX));
        for(auto &e: edges)
            gf[e[0]][e[1]] = e[2];
        
        for(int i = 0; i<n; i++) gf[i][i] = 0;
        
        for(int k = 0; k<n; k++)
            for(int j = 0; j<n; j++)
                for(int i = 0; i<n; i++)
                    gf[i][j] = min(1ll*gf[i][j], 1ll*gf[i][k] + gf[k][j]);
        
    }
    
    void addEdge(vector<int> e) {
        for(int i = 0; i<V; i++)
            for(int j = 0; j<V; j++)
                gf[i][j] = min(1ll*gf[i][j], 1ll*gf[i][e[0]] + e[2] + gf[e[1]][j]);
    }
    
    int shortestPath(int node1, int node2) {
        return gf[node1][node2] == INT_MAX?-1:gf[node1][node2];        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */