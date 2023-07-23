class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        long long sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum >= 1ll*(cnt+1)*(cnt+2)/2){
                cnt++;
            }
        }
        return cnt;
    }
};