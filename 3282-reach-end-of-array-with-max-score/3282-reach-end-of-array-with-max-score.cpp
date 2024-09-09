class Solution {
public:
    long long findMaximumScore(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> stk;
        int i = n-1;
        while(i>=0){
            while(!stk.empty() and arr[stk.top()] <= arr[i]) stk.pop();
            if(stk.empty())
                nge[i] = n-1;
            else
                nge[i] = stk.top();
            stk.push(i--);
        }
        long long ans = 0;
        int cur = 0;
        while(cur<n-1){
            ans += 1ll*arr[cur]*(nge[cur] - cur);
            cur = nge[cur];
        }
        return ans;
    }
};