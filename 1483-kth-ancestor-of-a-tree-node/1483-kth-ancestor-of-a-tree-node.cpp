class TreeAncestor {
    vector<vector<int> >st;
    vector<int> depth;
    int lg;
    int dfs(int node){
        if(depth[node] != -1) return depth[node];
        return depth[node] = dfs(st[node][0]) + 1;
    }
public:
    TreeAncestor(int n, vector<int>& parent): 
        st(n, vector<int>(__lg(n) + 1)) , depth(n, -1) 
    {
        lg = __lg(n) + 1;
        parent[0] = 0;
        depth[0] = 0;
        for(int i = 0; i<n; i++) st[i][0] = parent[i];
        for(int i = 0; i<n; i++) dfs(i);
        for(int j = 1; j<lg; j++){
            for(int i = 0; i<n; i++){
                st[i][j] = st[ st[i][j-1] ][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) return -1;
                
        for(int i = 0; i<lg; i++)
            if(k&(1<<i)) node = st[node][i];
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */