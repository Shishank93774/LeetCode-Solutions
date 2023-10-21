class Solution {
public:
    int constrainedSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int ans = arr[0];
        
        priority_queue<pair<int, int> > pqu;
        pqu.push({arr[0], 0});
        
        for(int i = 1; i<n; i++){
            while(!pqu.empty() and i - pqu.top().second > k) pqu.pop();
            
            int cur = max(arr[i], arr[i] + pqu.top().first);
            pqu.push({cur, i});
            ans = max(ans, cur);
        }
        
        return ans;
        
    }
};