const int N = 4e2+2, MXOR = 128;  
bool dpf[N][N][MXOR], dpr[N][N][MXOR];
class Solution {
public:
    int maxValue(vector<int>& arr, int k) {
        int n = arr.size();
        
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<=n; j++)
                for(int orr = 0; orr<MXOR; orr++)
                    dpf[i][j][orr] = dpr[i][j][orr] = false;
        
        dpf[0][0][0] = true;
        for(int i = 0; i<n; i++){
            for(int k1 = 0; k1<=k; k1++){
                for(int orr = 0; orr<MXOR; orr++){
                    if(dpf[i][k1][orr]){
                        dpf[i+1][k1][orr] = true;
                        
                        if(k1 < k){
                            dpf[i+1][k1+1][orr|arr[i]] = true;
                        }
                        
                    }
                }
            }
        }
        
        dpr[n][0][0] = true;
        for(int i = n-1; i>=0; i--){
            for(int k2 = 0; k2<=k; k2++){
                for(int orr = 0; orr<MXOR; orr++){
                    if(dpr[i+1][k2][orr]){
                        dpr[i][k2][orr] = true;
                        
                        if(k2 < k){
                            dpr[i][k2+1][orr|arr[i]] = true;
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        
        for(int part = k-1; part+k<=n; part++){
            for(int orl = 0; orl<MXOR; orl++){
                if(dpf[part][k][orl]){
                    for(int orr = 0; orr<MXOR; orr++){
                        if(dpr[part][k][orr]){
                            ans = max(ans, orl^orr);
                        }
                    }
                }
            }
        }
        
        return ans;
        
    }
};