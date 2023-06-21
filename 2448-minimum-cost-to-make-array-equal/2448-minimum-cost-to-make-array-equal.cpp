class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& cost) {
        int n = arr.size();
//         vector<pair<int, int> > vec;
        
//         for(int i = 0; i<n; i++) vec.push_back({arr[i], cost[i]});
//         sort(vec.begin(), vec.end());
        
//         int mid = 0;
//         long long sum = 0, tot = accumulate(cost.begin(), cost.end(), 0ll);
//         int i = 0;
//         while(i<n and sum<(tot+1)/2){
//             sum += vec[i].second;
//             mid = vec[i].first;
//             i++;
//         }
        
        auto fun = [&](int mid)->long long{
            long long res = 0;
            for(int i = 0; i<n; i++) res += 1ll*abs(arr[i] - mid)*cost[i];
            return res;
        };
//         return fun(mid);
        
        int l = 2, r = 1e6+6;
        long long ans = fun(1);
        while(l<=r){
            int mid = l + (r-l)/2;
            long long y1 = fun(mid), y2 = fun(mid+1);
            ans = min(y1, y2);
            if(y1<y2)
                r = mid-1;
            else
                l = mid+1;

        }
        return ans;
    }
};