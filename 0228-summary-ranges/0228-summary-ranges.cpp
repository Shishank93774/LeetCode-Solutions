class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string cur;
        int i = 0, n = nums.size();
        while(i<n){
            int j = i+1;
            while(j<n and nums[j] == nums[j-1]+1) j++;
            if(j == i+1) ans.push_back(to_string(nums[i]));
            else ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            i = j;
        }
        return ans;
    }
};