class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and nums[stk.top()] <= nums[i]) stk.pop();
            stk.push(i);
        }
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and nums[stk.top()] <= nums[i]) stk.pop();
            if(stk.empty()) ans[i] = -1;
            else ans[i] = nums[stk.top()];
            stk.push(i);
        }
        return ans;
    }
};