int n, x, mn;
class Solution {
    // bool chk(vector<int> &arr, int k, vector<int> &pre){
    //     for(int i = k; i<=n; i++) if(pre[i] - pre[i-k] >= x) return true;
    //     return false;
    // }
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        n = arr.size(), mn = INT_MAX, x = target;
        /*
        O(n^2): (TLE)
            int l = 0, r = 0;
            while(r<n){
                while(r<n and pre[r] - pre[l] < x) r++;
                if(pre[r] - pre[l] >= x){
                    mn = min(mn, r - l);
                }else{
                    break;
                }
                l++;
                r = l;
            }
        */
        /*
        O(n log(n)): (AC- 114ms)
            // Don't forget to deComment the chk funtion. :)
            int l = 1, r = n;
            vector<int> pre(n+1);
            pre[0] = 0;
            for(int i = 1; i<=n; i++) pre[i] = pre[i-1] + arr[i-1];
            while(l<=r){
                int mid = l + (r-l)/2;
                if(chk(arr, mid, pre)){
                    mn = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        */
        // /*
        // O(n): (AC obviously - 41ms)
            int l = 0, r = 0, sum = 0;
            while(r<n and l<n){
                sum += arr[r];
                while(sum >= x){
                    mn = min(mn, r - l + 1);
                    sum -= arr[l];
                    l++;
                }
                r++;
            }
        // */
        return mn == INT_MAX?0:mn;
    }

};