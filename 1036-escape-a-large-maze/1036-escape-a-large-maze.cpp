int dxy[5] = {0, 1, 0, -1, 0};
const int N = 1e6;
class Solution {
    unordered_map<int, unordered_set<int> > vis;
    bool valid(int x, int y){
        if(x<0 or y<0 or x>=N or y>=N or (vis.find(x) != vis.end() and vis[x].find(y) != vis[x].end())) return false;
        return true;
    }
    int bfs(vector<int>& source, vector<int>& target, int till){
        
        queue<vector<int> > qu;
        qu.push(source);
        int dist = 0;
        while(!qu.empty()){
            if(dist > till) return 1;
            int sz = qu.size();
            while(sz--){
                auto v = qu.front(); qu.pop();
                
                if(v == target) return 2;
                int x = v[0], y = v[1];
                
                for(int i = 0; i<4; i++){
                    int tx = x + dxy[i], ty = y + dxy[i+1];
                    if(valid(tx, ty)){
                        vis[tx].insert(ty);
                        qu.push({tx, ty});
                    }
                }
            }
            dist++;
        }
        return 0;
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vis.clear();
        for(auto &e: blocked){
            int x = e[0], y = e[1];
            vis[x].insert(y);
        }
        int chk = bfs(source, target, blocked.size());
        
        if(chk == 0) return false;
        if(chk == 2) return true;
        vis.clear();
        for(auto &e: blocked){
            int x = e[0], y = e[1];
            vis[x].insert(y);
        }
        return bfs(target, source, blocked.size());
    }
};