class Solution {
public:
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        
        stack<int> stk;
        
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) nse[i] = n;
            else nse[i] = stk.top();
            stk.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int p = pse[i], nn = nse[i];
            if(p < k and k < nn){
                ans = max(ans, (nn - p - 1)*arr[i]);
            }
        }
        
        return ans;
        
    }
};