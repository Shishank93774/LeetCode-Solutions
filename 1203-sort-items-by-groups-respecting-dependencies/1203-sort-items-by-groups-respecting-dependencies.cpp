class Solution {
public:
    void tpSort(vector<vector<int>> &g, vector<int> &indegree, vector<int> &visited)
{
    queue<int> q;
    for( int i = 0; i < indegree.size(); i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visited.push_back(node);
        for( auto v : g[node])
        {
            if(--indegree[v] == 0)
                q.push(v);
        }
    }
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {   
    int group_id = m;
    for( int i = 0; i < n; i++)
    {
        if(group[i] == -1)
            group[i] = group_id++;
    }
    
    vector<int> item_indegree(n, 0);
    vector<vector<int>> item_graph(n);
    
    vector<int> group_indegree(group_id, 0);
    vector<vector<int>> group_graph(group_id);        
    
    for( int i = 0; i < n; i++)
    {
        for(int item : beforeItems[i])
        {
            item_graph[item].push_back(i);
            item_indegree[i]++;
            if(group[i] != group[item])
            {
                group_indegree[group[i]]++;
                group_graph[group[item]].push_back(group[i]);
            }
        }
    }
    
    vector<int> item_sorted;
    vector<int> group_sorted;
    tpSort(item_graph, item_indegree, item_sorted);
    tpSort(group_graph, group_indegree, group_sorted);
    
    if(item_sorted.size() != n || group_sorted.size() != group_id )
        return {};
    
    vector<int> ans;
    unordered_map<int, vector<int>> umap;
    
    for( int elem : item_sorted )
        umap[group[elem]].push_back(elem);
    
    for( int gp_elem : group_sorted)
        ans.insert(ans.end(), umap[gp_elem].begin(), umap[gp_elem].end());
    
    return ans;
}
};