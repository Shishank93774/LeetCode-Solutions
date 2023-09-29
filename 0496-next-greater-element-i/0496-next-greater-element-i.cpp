class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> memo;
        stack<int> stk;
        int n = nums2.size();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and nums2[stk.top()] < nums2[i]) stk.pop();
            if(stk.empty()) memo[nums2[i]] = -1;
            else memo[nums2[i]] = nums2[stk.top()];
            stk.push(i);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i<nums1.size(); i++) ans[i] = memo[nums1[i]];
        return ans;
    }
};