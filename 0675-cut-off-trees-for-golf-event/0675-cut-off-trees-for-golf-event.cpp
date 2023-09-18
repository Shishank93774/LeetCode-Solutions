int dxy[5] = {0, 1, 0, -1, 0};

class Solution {
    int nextPathDist(int sr, int sc, int dr, int dc, vector<vector<int> > &forest){
        int n = forest.size(), m = forest[0].size();
        
        queue<pair<int, int> > qu;
        qu.push({sr, sc});
        vector<vector<char> > vis(n, vector<char>(m, 0));
        vis[sr][sc] = 1;
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                auto [r, c] = qu.front(); qu.pop();
                if(r == dr and c == dc) return d;
                
                for(int i = 0; i<4; i++){
                    int tr = r + dxy[i], tc = c + dxy[i+1];
                    if(tr<0 or tc<0 or tr>=n or tc>=m or forest[tr][tc] == 0 or vis[tr][tc]) continue;
                    vis[tr][tc] = 1;
                    qu.push({tr, tc});
                }
            }
            d++;
        }
        
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        
        vector<vector<int> > visitingOrder;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(forest[i][j] > 1) visitingOrder.push_back({forest[i][j], i, j});
            }
        }
        sort(visitingOrder.begin(), visitingOrder.end());
        int curRow = 0, curCol = 0;
        int ans = 0;
        
        for(int i = 0; i<visitingOrder.size(); i++){
            int nxtRow = visitingOrder[i][1], nxtCol = visitingOrder[i][2];
            
            int req = nextPathDist(curRow, curCol, nxtRow, nxtCol, forest);
            
            if(req == -1) return -1;
            ans += req;
            curRow = nxtRow, curCol = nxtCol;
        }
        
        return ans;
        
    }
};