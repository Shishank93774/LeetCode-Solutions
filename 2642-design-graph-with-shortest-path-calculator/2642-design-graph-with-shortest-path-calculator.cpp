class Graph {
    vector<vector<pair<int, int> > > adj;
    int V;
public:
    Graph(int n, vector<vector<int>>& edges) {
        V = n;
        adj.resize(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu;
        pqu.push({0, node1});
        vector<int> dist(V+1, INT_MAX);
        while(!pqu.empty()){
            auto pr = pqu.top(); pqu.pop();
            if(pr.second == node2) return pr.first;
            if(dist[pr.second] < pr.first) continue;
            dist[pr.second] = pr.first;
            for(auto nbrPr: adj[pr.second]){
                if(1ll*nbrPr.second + pr.first < 1ll*dist[nbrPr.first]) pqu.push({nbrPr.second + pr.first, nbrPr.first});
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */