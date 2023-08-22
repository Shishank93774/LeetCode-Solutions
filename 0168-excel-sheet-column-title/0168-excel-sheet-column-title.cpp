class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            n--;
            int r = n%26;
            ans += (char)('A' + r);
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};