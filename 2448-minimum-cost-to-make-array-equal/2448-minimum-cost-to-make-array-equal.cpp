class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& cost) {
        int n = arr.size();
        vector<pair<int, int> > vec;
        
        for(int i = 0; i<n; i++) vec.push_back({arr[i], cost[i]});
        sort(vec.begin(), vec.end());
        
        int mid = 0;
        long long sum = 0, tot = accumulate(cost.begin(), cost.end(), 0ll);
        int i = 0;
        while(i<n and sum<(tot+1)/2){
            sum += vec[i].second;
            mid = vec[i].first;
            i++;
        }
        
        auto fun = [&](int mid)->long long{
            long long res = 0;
            for(int i = 0; i<n; i++) res += 1ll*abs(vec[i].first - mid)*vec[i].second;
            return res;
        };
        return fun(mid);
    }
};