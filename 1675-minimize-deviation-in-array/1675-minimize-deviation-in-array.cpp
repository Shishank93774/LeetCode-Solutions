class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pqu;
        int mn = INT_MAX;
        int ans = INT_MAX;
        for(int x: nums) {x = x%2?x*2:x; mn = min(mn, x); pqu.push(x);}
        while(!pqu.empty()){
            if(pqu.top()&1) break;
            int lar = pqu.top(); pqu.pop();
            ans = min(ans, lar - mn);
            mn = min(mn, lar/2);
            pqu.push(lar/2);
        }
        if(pqu.size()) ans = min(ans, pqu.top() - mn);
        return ans;
    }
};