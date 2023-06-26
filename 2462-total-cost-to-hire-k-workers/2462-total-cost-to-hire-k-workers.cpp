class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int> > pqu1, pqu2;
        int l = 0, r = costs.size() - 1;
        int cnt = 0;
        long long ans = 0;
        while(cnt < k){
            while(l<=r and pqu1.size() < candidates) pqu1.push(costs[l++]);
            while(l<=r and pqu2.size() < candidates) pqu2.push(costs[r--]);
            int t1 = INT_MAX, t2 = INT_MAX;
            if(pqu1.size()) t1 = pqu1.top();
            if(pqu2.size()) t2 = pqu2.top();
            ans += min(t1, t2);
            if(t1 <= t2)
                pqu1.pop();
            else
                pqu2.pop();
            cnt++;
        }
        return ans;
    }
};