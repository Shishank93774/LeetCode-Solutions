class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        auto dfs = [&](int src, auto &&dfs) -> pair<long long, int> { // sum, req
            if(src >= n) return {0ll, 0};
            int req = 0;
            long long sum = cost[src];
            auto lh = dfs(2*src+1, dfs);
            auto rh = dfs(2*src+2, dfs);
            long long d = abs(lh.first - rh.first);
            req = (lh.second + rh.second + d);
            sum = sum + max(lh.first, rh.first);
            return {sum, req};
        };
        
        auto pr = dfs(0, dfs);
        return pr.second;
    }
};