class Solution {
public:
    int minimizeMax(vector<int> &arr, int p) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        auto chk = [&](const int diff)->bool{
            int i = 1;
            int cnt = 0;
            while(i<n){
                if(arr[i] - arr[i-1] <= diff){
                    cnt++;
                    i += 2;
                }else{
                    i++;
                }
            }
            return (cnt >= p);
        };
        
        int l = 0, r = arr[n-1] - arr[0];
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return r+1;
        
    }
};