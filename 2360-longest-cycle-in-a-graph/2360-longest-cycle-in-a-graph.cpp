class Solution{
public:
    int mx;
    void dfs(int node, vector<int> &edges, vector<int> &distance_from_start_node, vector<bool> &visited, int current_len)
    {
        if (!visited[node]) {
            visited[node] = true;
            distance_from_start_node[node] = current_len;

            if (edges[node] != -1) dfs(edges[node], edges, distance_from_start_node, visited, current_len + 1);
            
            distance_from_start_node[node] = -1;
        }
        else {
            if (distance_from_start_node[node] != -1)  mx = max(current_len - distance_from_start_node[node], mx);
            }
    }
    int longestCycle(vector<int> &edges)
    {
        mx = -1;
        vector<bool> visited(edges.size(), false);
        vector<int> length(edges.size(), -1);
        for (int i = 0; i < edges.size(); ++i) {
            if (!visited[i]) {
                dfs(i, edges, length, visited, 0);
            }
        }
        return mx;
    }
};
