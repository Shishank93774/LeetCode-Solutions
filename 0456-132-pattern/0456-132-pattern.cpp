class Solution {
public:
    bool find132pattern(const vector<int>& nums) {
        
        int s3 = -1e9;
        stack<int> stk;
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i] < s3) return true;
            else while(!stk.empty() and nums[stk.top()] < nums[i]) {
                s3 = nums[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }
        return false;
    }
};