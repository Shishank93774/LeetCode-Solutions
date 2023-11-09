const int mod = 1e9+7;
class Solution {
public:
    int countHomogenous(const string &str) {
        long long ans = 0;
        int i = 0, n = str.size();
        while(i<n){
            int j = i+1;
            long long cnt = 1;
            while(j<n and str[i] == str[j]) j++, cnt++;
            i = j;
            ans = (ans + cnt*(cnt+1)/2);
            ans %= mod;
        }
        return ans;
    }
};