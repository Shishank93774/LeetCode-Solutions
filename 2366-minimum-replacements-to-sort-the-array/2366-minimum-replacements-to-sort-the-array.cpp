class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        if(n == 1) return 0;
        int x = arr[n-1];
        int i = n-2;
        
        while(i>=0){
            if(arr[i] <= x){
                x = arr[i];
            }else{
                int d = (arr[i] + x - 1)/x;
                ans += (arr[i] - 1)/x;
                x = arr[i]/d;
            }
            i--;
        }
        
        return ans;
        
    }
};