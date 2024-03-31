class Solution {
public:
    int minimumDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        multiset<int> s1, s2;
        for(int i = 0; i<n; i++){
            int s = arr[i][0] + arr[i][1];
            int d = arr[i][0] - arr[i][1];
            s1.insert(s);
            s2.insert(d);
        }
        
        int ans = 1e9;
        for(int i = 0; i<n; i++){
            int s = arr[i][0] + arr[i][1];
            int d = arr[i][0] - arr[i][1];
            
            s1.erase(s1.find(s));
            s2.erase(s2.find(d));
            
            ans = min(ans, max(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin()));
            
            s1.insert(s);
            s2.insert(d);
        }
        
        return ans;
    }
};