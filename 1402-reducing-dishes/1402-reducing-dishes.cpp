class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int sum = 0, ans = 0;
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i<arr.size() and sum + arr[i] > 0; i++){
            sum += arr[i];
            ans += sum;
        }
        return ans;
    }
};