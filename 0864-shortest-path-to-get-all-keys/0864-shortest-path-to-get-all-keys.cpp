struct point{
    int x, y;
    int mv;
    int has;
};

int dxy[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& arr) {
        queue<point> qu;
        int tot = 0;
        int n = arr.size(), m = arr[0].size();
        set<int> vis[n][m];
        vector<char> keys;
        map<char, int> mp;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                vis[i][j].clear();
                if(arr[i][j] == '@') qu.push({i, j, 0, 0});
                else if('a' <= arr[i][j]  and arr[i][j] <= 'z'){
                    mp[arr[i][j]] = keys.size();
                    keys.push_back(arr[i][j]);
                    tot++;
                }
            }
        }
        int req = (1<<tot) - 1;
        int sz = keys.size();
        for(int i = 0; i<sz; i++)
            keys.push_back(keys[i] - 32);
        
        while(!qu.empty()){
            point p = qu.front(); qu.pop();
            int x = p.x, y = p.y, mv = p.mv, has = p.has;
            
            if((has&req) == req) return mv;
            
            if(vis[x][y].find(has) != vis[x][y].end()) continue;
            vis[x][y].insert(has);
            
            for(int i = 0; i<4; i++){
                int tx = x + dxy[i][0], ty = y + dxy[i][1];
                if(tx < 0 or ty <0 or tx>=n or ty >= m or arr[tx][ty] == '#') continue;
                char ch = arr[tx][ty];
                if(ch == '.' or ch == '@') qu.push({tx, ty, mv+1, has});
                else if('a' <= ch and ch <= 'z'){
                    int pos = mp[ch];
                    qu.push({tx, ty, mv+1, has|(1<<pos)});
                }else{
                    int pos = mp[ch+32];
                    if(has&(1<<pos)){
                        qu.push({tx, ty, mv+1, has});
                    }
                }
            }
        }
        return -1;
    }
};