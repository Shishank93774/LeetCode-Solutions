class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int l = 1, r = nums.size() - 1;
        
        while(l<=r){
            int mid = (l + r)/2;
            int cnt = 0;
            
            for(int &x: nums){
                cnt += (x <= mid);
            }
            if(cnt > mid) r = mid - 1;
            else l = mid+1;
        }
        return r+1;
        
    }
};