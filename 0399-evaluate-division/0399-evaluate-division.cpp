
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double> > >&graph, unordered_set<string> &Vis, string &src, string &dest, double ansSoFar, double &ans){
        if(graph.find(src) == graph.end() or graph.find(dest) == graph.end()){
            ans = -1.0;
            return;
        }
        if(Vis.find(src) != Vis.end())return;  
        Vis.insert(src);
        if(dest == src){
            ans = ansSoFar;
            return;
        }
        for(pair<string, double> pr: graph[src]){
            string newSrc = pr.first;
            double val = pr.second;
            if(Vis.find(newSrc) != Vis.end())continue;
            ansSoFar *= val;
            dfs(graph, Vis, newSrc, dest, ansSoFar, ans);
            if(dest == newSrc){ans = ansSoFar; return;}
            ansSoFar /= val;
        }
        Vis.erase(src);
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double> > >graph;
        unordered_set<string> Vis;
        int n = equations.size();
        for(int i = 0; i<n; i++){
            string src = equations[i][0];
            string dest = equations[i][1];
            double cost = values[i];
            graph[src].push_back({dest, cost});
            graph[dest].push_back({src, 1.0/cost});
        }
        int q = queries.size();
        vector<double> ans;
        for(int i = 0; i<q; i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            double val = -1.0;
            dfs(graph, Vis, src, dest, 1.0, val);
            ans.push_back(val);
            Vis.clear();
        }
        return ans;
    }
};