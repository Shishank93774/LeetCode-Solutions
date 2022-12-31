
class Solution{
public:
    int minStoneSum(vector<int> &piles, int k){
        int cnt[10004] = {};

        for(int v : piles) cnt[v]++;
        for(int i = 10004-1; i > 0 && k; i--){
            const int removed = min(k, cnt[i]);
            cnt[i - (i / 2)] += removed;
            k -= removed;
            cnt[i] -= removed;
        }
        int ans = 0;
        for(int i = 1'0000; i > 0; i--) ans += i * cnt[i];
        return ans;
    }
};