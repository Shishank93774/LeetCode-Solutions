class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        int l = 1;
        sort(meetings.begin(), meetings.end());
        
        for(auto &v: meetings){
            ans += max(0, v[0] - l);
            l = max(l, v[1] + 1);
        }
        ans += max(0, days-l+1);
        
        return ans;
    }
};