class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((nums1[i]%(nums2[j]*k)) == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};