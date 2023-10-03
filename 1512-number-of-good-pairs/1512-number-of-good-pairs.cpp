class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101] = {0}, ans = 0;
        for(int &x: nums) ans += cnt[x]++;
        return ans;
    }
};