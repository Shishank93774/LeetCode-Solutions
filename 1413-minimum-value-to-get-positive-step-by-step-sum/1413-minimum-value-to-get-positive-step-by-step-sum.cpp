class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, sum = 0;
        for(int x: nums){
            sum += x;
            mn = min(mn, sum);
        }
        return 1-mn;
    }
};