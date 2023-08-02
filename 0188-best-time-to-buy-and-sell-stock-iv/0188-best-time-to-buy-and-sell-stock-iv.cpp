class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > down(k+1, vector<int>(2, 0));
        vector<vector<int> > cur(k+1, vector<int>(2, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int remk = 1; remk<=k; remk++){
                cur[remk][0] = max(down[remk][0], - arr[i] + down[remk][1]);
                cur[remk][1] = max(down[remk][1], arr[i] + down[remk-1][0]);
            }
            down = cur;
        }
        
        return down[k][0];
    }
};