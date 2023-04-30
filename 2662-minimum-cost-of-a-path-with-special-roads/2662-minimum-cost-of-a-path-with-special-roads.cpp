#define ll long long

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
const long long N = 1e6;

class Solution {
public:
    ll dist(ll x, ll y){
        return (abs(x/N - y/N) + abs(x%N - y%N));
    }
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& rds) {
        ll src = 1ll*start[0]*N + start[1];
        ll dest = 1ll*target[0]*N + target[1];
        if(src == dest) return 0;
        unordered_map<ll, vector<pair<ll, ll> > > mp; 
        mp[src].push_back({abs(target[0] - start[0]) + abs(target[1] - start[1]), dest});
        for(auto vec: rds){
            ll u =  vec[0]*N + vec[1];
            ll v = vec[2]*N + vec[3];
            ll cost = vec[4];
            ll gCost = abs(vec[2] - vec[0]) + abs(vec[3] - vec[1]);
            mp[u].push_back({min(gCost, cost), v});
            mp[v].push_back({gCost, u});
            if(u != src){
                int dd = dist(u, src);
                mp[src].push_back({dd, u});
            }
            if(u != dest){
                int dd = dist(u, dest);
                mp[u].push_back({dd, dest});
            }
            if(v != src){
                int dd = dist(v, src);
                mp[src].push_back({dd, v});
            }
            if(v != dest){
                int dd = dist(v, dest);
                mp[v].push_back({dd, dest});
            }
        }
        for(int i = 0; i<rds.size(); i++){
            for(int j = 0; j<rds.size(); j++){
                if(i == j) continue;
                ll u = rds[i][2]*N + rds[i][3];
                ll v = rds[j][0]*N + rds[j][1];
                ll cst = abs(rds[i][2] - rds[j][0]) + abs(rds[i][3] - rds[j][1]);
                if(u != v){
                    mp[u].push_back({cst, v});
                    mp[v].push_back({cst, u});
                }
            }
        }
        unordered_map<ll, ll> dist;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pqu;
        pqu.push({0ll, src});
        dist[src] = 0ll;
        while(!pqu.empty()){
            pair<ll, ll> pr = pqu.top(); pqu.pop();
            ll w = pr.first, f = pr.second;
            for(auto nbrPr: mp[f]){
                ll wt = nbrPr.first;
                ll nbr = nbrPr.second;
                if((dist.find(nbr) == dist.end()) or (dist[nbr] > dist[f] + wt)){
                    dist[nbr] = dist[f] + wt;
                    pqu.push({dist[nbr], nbr});
                }
            }
        }
        return dist[dest];
    }
};