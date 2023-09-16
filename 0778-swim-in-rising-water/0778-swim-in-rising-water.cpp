int dxy[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    int swimInWater(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pqu;
        vector<vector<int> > dp(n, vector<int>(m, 1e9));
        
        pqu.push({arr[0][0], 0, 0});
        dp[0][0] = 0;
        while(!pqu.empty()){
            auto f = pqu.top(); pqu.pop();
            
            int d = f[0], x = f[1], y = f[2];
            
            if(x == n-1 and y == m-1){
                return d;
            }
            
            for(int i = 0; i<4; i++){
                int tx = x + dxy[i], ty = y + dxy[i+1];
                if(tx<0 or ty<0 or tx>=n or ty>=m) continue;
                if(dp[tx][ty] > max(arr[tx][ty], d)){
                    dp[tx][ty] = max(arr[tx][ty], d);
                    pqu.push({dp[tx][ty], tx, ty});
                }
            }
        }
        
        return -1;
    }
};