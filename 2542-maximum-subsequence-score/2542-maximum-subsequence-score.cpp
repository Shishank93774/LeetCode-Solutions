class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int> > brr(n);
        for(int i = 0; i<n; i++) brr[i].first = nums2[i], brr[i].second = i;
        sort(brr.begin(), brr.end());
        
        vector<int> corr(n);
        for(int i = 0; i<n; i++) corr[i] = nums1[brr[i].second];
        
        // priority_queue<int, vector<int>, greater<int> > pqu;
        multiset<int> mst;
        
        long long suf = 0;
        // for(int i = n-k; i<n; i++) pqu.push(corr[i]), suf += corr[i];
        for(int i = n-k; i<n; i++) mst.insert(corr[i]), suf += corr[i];

        long long ans = suf*brr[n-k].first;
        
        for(int i = n-k-1; i>=0; i--){
            suf += corr[i];
            mst.insert(corr[i]);
            suf -= *mst.begin(); mst.erase(mst.begin());
            ans = max(ans, suf*brr[i].first);
        }
        return ans;
    }
};