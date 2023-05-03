class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> st(nums2.begin(), nums2.end());
        set<int> tmp;
        for(int x: nums1) if(st.find(x) == st.end()) tmp.insert(x);
        st = unordered_set<int>(nums1.begin(), nums1.end());
        ans.push_back(vector<int>(tmp.begin(), tmp.end()));
        tmp.clear();
        for(int x: nums2) if(st.find(x) == st.end()) tmp.insert(x);
        ans.push_back(vector<int>(tmp.begin(), tmp.end()));
        return ans;
    }
};