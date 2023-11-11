const int INF = 1e9;
class Graph {
    int graph[101][101];
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) graph[i][j] = ((i==j)?0:INF);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            graph[u][v] = w;
        }
        for(int k = 0; k<n; k++)
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++)
                    if(graph[i][k] != INF and graph[k][j] != INF)
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(graph[i][u] != INF and graph[v][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][u] + w + graph[v][j]);
    }
    
    int shortestPath(int node1, int node2) {
        int w = graph[node1][node2];
        return w==INF?-1:w;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */