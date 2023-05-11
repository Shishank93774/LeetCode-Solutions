const int N = 501;
int dp[N][N];

class Solution {
    int rec(int i, int j, vector<int> &arr, unordered_map<int, vector<int> > &mp, int n){
        if(i == n) return 0;
        int x = arr[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int &ans = dp[i][j] = rec(i+1, j, arr, mp, n);
        if(mp.find(x) != mp.end()){
            auto v = mp[x];
            auto it = lower_bound(v.begin(), v.end(), j);
            if(it != v.end()){
                ans = max(ans, 1 + rec(i+1, *it+1, arr, mp, n));
            }
        }
        return ans;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int> > mp;
        int n = nums1.size(), m = nums2.size();
        for(int i = 0; i<nums2.size(); i++) mp[nums2[i]].push_back(i);
        
        memset(dp, -1, sizeof dp);
        return rec(0, 0, nums1, mp, n);
    }
};