class Solution {
public:
    int findMaxForm(vector<string>& strs, int z, int o) {
        
        vector<pair<int, int> > arr;
        for(string s: strs){
            int len = s.size();
            int z = count(s.begin(), s.end(), '0');
            arr.push_back({z, len-z});
        }
        
        int n = arr.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(z+1, vector<int>(o+1, -1)));
        auto rec = [&](int i, int remz, int remo, auto &&rec)->int{
            if(remz<0 or remo<0) return 0;
            if(i == n) return 0;
            
            if(dp[i][remz][remo] != -1) return dp[i][remz][remo];
            
            int ans = rec(i+1, remz, remo, rec);
            
            if(remz >= arr[i].first and remo >= arr[i].second)
                ans = max(ans, 1 + rec(i+1, remz-arr[i].first, remo - arr[i].second, rec));
            
            return dp[i][remz][remo] = ans;
        };
        
        return rec(0, z, o, rec);
    }
};