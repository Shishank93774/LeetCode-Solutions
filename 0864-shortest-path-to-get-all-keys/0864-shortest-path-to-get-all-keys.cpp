struct point{
    int x, y; // my co-ordinates
    int mv; // moves I have done so far
    int has; // what keys I have 
};

int dxy[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // traversing helper

class Solution {
public:
    int shortestPathAllKeys(vector<string>& arr) {
        queue<point> qu; // for BFS
        int tot = 0; // no. of keys
        int n = arr.size(), m = arr[0].size();
        unordered_set<int> vis[n][m]; // visited array
        vector<char> keys; // what keys do I have?
        map<char, int> mp; // position of key in the keys array

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                vis[i][j].clear(); 
                if(arr[i][j] == '@') qu.push({i, j, 0, 0}); // initial node
                else if('a' <= arr[i][j]  and arr[i][j] <= 'z'){
                    mp[arr[i][j]] = keys.size(); // this key is in this position
                    keys.push_back(arr[i][j]); // adding key to keys
                    tot++;
                }
            }
        }
        int req = (1<<tot) - 1; // WHY?
        
        while(!qu.empty()){
            point p = qu.front(); qu.pop();
            int x = p.x, y = p.y, mv = p.mv, has = p.has;
            
            if((has&req) == req) return mv; // WHY?
            
            if(vis[x][y].find(has) != vis[x][y].end()) continue;
            vis[x][y].insert(has);
            
            for(int i = 0; i<4; i++){
                int tx = x + dxy[i][0], ty = y + dxy[i][1];
                if(tx < 0 or ty <0 or tx>=n or ty >= m or arr[tx][ty] == '#') continue;
                char ch = arr[tx][ty];
                if(ch == '.' or ch == '@') qu.push({tx, ty, mv+1, has}); // Case 1
                else if('a' <= ch and ch <= 'z'){ // Case 2
                    int pos = mp[ch];
                    qu.push({tx, ty, mv+1, has|(1<<pos)}); // Making the i-th bit SET 
                }else{ // Case 3
                    int pos = mp[ch+32];
                    if(has&(1<<pos)){  // Checking the i-th bit
                        qu.push({tx, ty, mv+1, has});
                    }
                }
            }
        }
        return -1; // No Answer
    }
};