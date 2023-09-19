class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int i = 0, n = nums.size();
        while(i<n){
            int tar = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[l] + nums[r];
                
                if(sum < tar) l++;
                else if(sum > tar) r--;
                else{
                    vector<int> a = {nums[i], nums[l], nums[r]};
                    ans.push_back(a);
                    
                    while(l<r and nums[l] == a[1]) l++;
                    while(l<r and nums[r] == a[2]) r--;
                    
                }
            }
            while(i<n and nums[i] == -tar) i++;
        }
        
        return ans;
    }
};