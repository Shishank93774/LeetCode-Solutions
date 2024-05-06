#define ll long long
const int mod = 1e9 + 7;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& arr, int cost1, int cost2) {
        int n = arr.size();
        
        cost2 = min(cost2, 2*cost1);
        ll tot = accumulate(arr.begin(), arr.end(), 0ll);
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        
        ll ans = 2e18;
        
        for(ll x = mx; x <= mx + 1e6;  x++){
            ll sum = n*x - tot;
            ll maxi = x - mn;
            
            if(maxi > (sum - maxi)){
                ll tg = (sum - maxi);
                ll sngl = maxi - (sum - maxi);
                
                ans = min(ans, tg*cost2 + sngl*cost1);                
            }else{
                ll tg = (sum/2);
                ll sngl = sum%2;
                
                ans = min(ans, tg*cost2 + sngl*cost1);
            }
        }
        
        return ans%mod;
    }
};