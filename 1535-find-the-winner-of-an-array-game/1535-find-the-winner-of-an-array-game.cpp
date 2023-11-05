class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        stack<int> stk;
        vector<int> nge(n);
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] < arr[i]) stk.pop();
            if(stk.empty()) nge[i] = n;
            else nge[i] = stk.top();
            stk.push(i);
        }
        
        int mx = *max_element(arr.begin(), arr.end());
        int i = 0;
        while(i<n and arr[i] != mx){
            if(i == 0 and nge[i] - i - 1 >= k){
                return arr[i];
            }else if(i != 0 and nge[i] - i >= k){
                return arr[i];
            }
            i++;
        }
        return mx;
    }
};