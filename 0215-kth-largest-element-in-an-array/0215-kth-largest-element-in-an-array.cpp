class Solution {
    int quickSelect(int l, int r, vector<int> &nums, int k){
        int pivot = r, pIdx = l, i = l;
        while(i < r){
            if(nums[i] <= nums[pivot]){
                swap(nums[i], nums[pIdx++]);
            }
            i++;
        }
        swap(nums[pivot], nums[pIdx]);
        if(pIdx < k){
            return quickSelect(pIdx+1, r, nums, k);
        }else if(pIdx > k){
            return quickSelect(l, pIdx-1, nums, k);
        }else{
            return nums[pIdx];
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k;
        return quickSelect(0, n-1, nums, k);
    }
};