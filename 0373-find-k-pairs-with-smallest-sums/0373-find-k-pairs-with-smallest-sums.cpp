class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<array<int, 3> > pqu;
        int n = nums1.size(), m = nums2.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int sum = nums1[i] + nums2[j];
                if(pqu.size() < k){
                    pqu.push({sum, nums1[i], nums2[j]});
                }else if(sum < pqu.top()[0]){
                    pqu.push({sum, nums1[i], nums2[j]});
                    pqu.pop();
                }else break;
            }
        }
        vector<vector<int> > ans;
        while(!pqu.empty()){
            auto [sum, u, v] = pqu.top(); pqu.pop();
            ans.push_back({u, v});
        }
        return ans;
    }
};