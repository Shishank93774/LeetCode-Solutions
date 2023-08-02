class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > down(2+1, vector<int>(2, 0));
        vector<vector<int> > cur(2+1, vector<int>(2, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int remk = 1; remk<=2; remk++){
                cur[remk][0] = max(down[remk][0], - arr[i] + down[remk][1]);
                cur[remk][1] = max(down[remk][1], arr[i] + down[remk-1][0]);
            }
            down = cur;
        }
        
        return down[2][0];
    }
};