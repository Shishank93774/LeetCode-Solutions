#define pdi pair<double, int>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double> > adj[n];
        for(int i = 0; i<succProb.size(); i++){
            auto e = edges[i];
            double d = succProb[i];
            adj[e[0]].push_back({e[1], d});
            adj[e[1]].push_back({e[0], d});
        }
        priority_queue<pdi> pqu;
        vector<double> ans(n, 0.0);
        ans[start] = 1.0;
        for(auto it: adj[start]) pqu.push({it.second, it.first});
        while(!pqu.empty()){
            auto f = pqu.top(); pqu.pop();
            double d = f.first;
            int src = f.second;
            if(src == end) return d;
            for(auto it: adj[src]){
                int nbr = it.first;
                double w = it.second;
                if(d*w > ans[nbr]) {
                    pqu.push({d*w, nbr});
                    ans[nbr] = d*w;
                }
            }
        }
        return 0;
    }
};