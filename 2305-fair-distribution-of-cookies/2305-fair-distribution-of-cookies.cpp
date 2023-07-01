class Solution {
    int mx;
    void rec(int i, vector<int> &arr, vector<int> &cur, int n, int k){
        if(i == n){
            mx = min(mx, *max_element(cur.begin(), cur.end()));
            return;
        }
        for(int j = 0; j<k; j++){
            cur[j] += arr[i];
            rec(i+1, arr, cur, n, k);
            cur[j] -= arr[i];
        }
    }
public:
    int distributeCookies(vector<int>& arr, int k) {
        mx = INT_MAX;
        vector<int> cur(k, 0);
        rec(0, arr, cur, arr.size(), k);
        return mx;
    }
};