class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int ans = 0, n = arr.size(), i = 0, j = 0, has0 = 0;
        while(i<n and j<n){
            while(j<n and (has0+(arr[j] == 0))<=k){
                ans = max(ans, j-i+1);
                has0 += (arr[j++] == 0);
            }
            has0 -= (arr[i++] == 0);
        }
        return ans;
    }
};