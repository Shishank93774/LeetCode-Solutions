class Solution {
    bool rec(int i, int krem, int curSum, const vector<int> &nums, const int avg, const int bit, const int n){
        if(krem == 0) return true;
        
        if(curSum == avg) return rec(0, krem-1, 0, nums, avg, bit, n);
        
        for(int j = i; j<n; j++){
            if((bit&(1<<j)) or (curSum + nums[j] > avg)) continue;
            if(rec(j+1, krem, curSum+nums[j], nums, avg, bit|(1<<j), n)) return true;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) return false;
        int avg = sum/k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > avg) return false;
        return rec(0, k, 0, nums, avg, 0, nums.size());
    }
};