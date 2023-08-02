class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> down(2, 0), down2(2, 0), cur(2, 0);
        
        for(int i = n-1; i>=0; i--){
            cur[0] = max(down[0], - arr[i] + down[1]);
            cur[1] = max(down[1], arr[i] + down2[0]);
            down2 = down;
            down = cur;
        }
        
        return down[0];
    }
};