const int N = 3e4+4, mod = 1e9+7;
int nse[N], pse[N];
#define ll long long

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()) nse[i] = n;
            else nse[i] = stk.top();
            stk.push(i);
        }

        ll ans = 0;
        for(int i = 0; i<n; i++){
            ll rng = (nse[i] - i) * (i - pse[i]);
            ll cur = rng*arr[i] % mod;
            ans += cur;
            ans %= mod;
        }
        return ans;
    }
};