class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int dest) {
        unordered_map<int, vector<int> > adj;
        
        for(int i = 0; i<routes.size(); i++){
            for(int j = 0; j<routes[i].size(); j++){
                adj[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> qu;
        qu.push(src);
        unordered_set<int> visNodes, visBuses;
        visNodes.insert(src);
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int u = qu.front(); qu.pop();
                if(u == dest) return d;
                for(int next: adj[u]){
                    if(visBuses.find(next) != visBuses.end()) continue;
                    visBuses.insert(next);
                    for(int v: routes[next]){
                        if(visNodes.find(v) != visNodes.end()) continue;
                        visNodes.insert(v);
                        qu.push(v);
                    }
                }
            }
            d++;
        }
        return -1;
    }
};