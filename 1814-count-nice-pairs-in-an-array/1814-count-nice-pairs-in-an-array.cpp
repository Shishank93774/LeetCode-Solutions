const int mod = 1e9+7;
class Solution {
    int rev(int n){
        int num = 0;
        while(n){
            num = num*10 + (n%10);
            n /= 10;
        }
        return num;
    }
public:
    int countNicePairs(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++){
            int rv = rev(arr[i]);
            ans += mp[arr[i] - rv]++;
            ans %= mod;
        }
        return ans;
    }
};