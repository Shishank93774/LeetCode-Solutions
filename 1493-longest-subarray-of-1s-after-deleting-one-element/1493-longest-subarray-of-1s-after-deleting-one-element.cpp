class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int ans = 0, n = arr.size(), i = 0, j = 0, has0 = 0;
        while(j<n){
            while(j<n and (has0+(arr[j] == 0))<2){
                ans = max(ans, j-i);
                has0 += (arr[j++] == 0);
            }
            j = max(j, i + 1);
            has0 -= (arr[i++] == 0);
        }
        return ans;
    }
};