class Solution {
    vector<long long> give(vector<int> &arr){
        int n = arr.size();
        
        stack<int> stk;
        vector<long long> ans(n);
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()){
                ans[i] = 1ll*(i+1)*arr[i];
            }else{
                ans[i] = 1ll*ans[stk.top()] + 1ll*(i - stk.top())*arr[i];
            }
            stk.push(i);
        }
        
        return ans;
    }
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        int n = arr.size();
        auto left = give(arr);
        reverse(arr.begin(), arr.end());
        auto right = give(arr);
        reverse(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long cur = 0;
            cur += left[i];
            cur += right[n-1-i];
            cur -= arr[i];
            ans = max(ans, cur);
        }
        
        return ans;
    }
};