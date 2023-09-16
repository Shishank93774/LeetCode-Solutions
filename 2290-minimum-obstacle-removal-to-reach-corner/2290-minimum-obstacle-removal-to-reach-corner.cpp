int dxy[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        
        deque<vector<int> > qu;
        
        qu.push_back({arr[0][0], 0, 0});
        vector<vector<int> > dp(n, vector<int>(m, 1e9));
        
        dp[0][0] = arr[0][0];
        
        while(!qu.empty()){
            auto f = qu.front(); 
            qu.pop_front();
            int w = f[0], x = f[1], y = f[2];
            
            if(x == n-1 and y == m-1){
                return w;
            }
            
            for(int i = 0; i<4; i++){
                int tx = x + dxy[i], ty = y + dxy[i+1];
                if(tx<0 or ty<0 or tx>=n or ty>=m) continue;
                if(dp[tx][ty] > w + arr[tx][ty]){
                    dp[tx][ty] = w + arr[tx][ty];
                    if(arr[tx][ty]){
                        qu.push_back({w+1, tx, ty});
                    }else{
                        qu.push_front({w, tx, ty});
                    }
                }
            }
        }
        return -1;
    }
};