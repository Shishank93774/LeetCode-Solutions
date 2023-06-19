class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, ans = 0;
        for(int x: gain){
            cur += x;
            ans = max(ans, cur);
        }
        return ans;
    }
};