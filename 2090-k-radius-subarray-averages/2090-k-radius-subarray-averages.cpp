class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n, -1);
        long long sum = 0;
        for(int i = 0; i<n and i<2*k; i++) sum += arr[i];
        int i = 2*k;
        while(i<n){
            sum += arr[i];
            ans[i-k] = sum/(2*k+1);
            sum -= arr[i - 2*k];
            i++;
        }
        return ans;
    }
};