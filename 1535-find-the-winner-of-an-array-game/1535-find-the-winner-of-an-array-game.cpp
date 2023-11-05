class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int cur = arr[0];
        int win = 0;
        int mx = *max_element(arr.begin(), arr.end());
        for(int i = 1; i<n; i++){
            int oppo = arr[i];
            if(cur > oppo) win++;
            else cur = oppo, win = 1;
            if(win == k or cur == mx) return cur;
        }
        return -1;
    }
};