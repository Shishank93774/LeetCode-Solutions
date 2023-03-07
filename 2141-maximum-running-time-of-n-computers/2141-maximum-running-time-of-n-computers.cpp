class Solution {
public:
    long long maxRunTime(int k, vector<int>& arr) {
        int n = arr.size();
        // long long tot = accumulate(arr.begin(), arr.end(), 0ll);
        // priority_queue<int> pqu(arr.begin(), arr.end());
        // while(!pqu.empty() and k > 0 and pqu.top() > tot / k){
        //     tot -= pqu.top(); k--; pqu.pop();
        // }
        // return tot/k;
        long long l = 0, r = accumulate(arr.begin(), arr.end(), 0ll)/k;
        long long ans = 0;
        while(l <= r){
            long long mid = l + (r - l)/2;
            int i = 0;
            long long timeTaken = 0;
            while(i<n){
                timeTaken += min(1ll*arr[i++], mid);
            }
            if(timeTaken >= k*mid){
                l = mid + 1;
                ans = mid;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};