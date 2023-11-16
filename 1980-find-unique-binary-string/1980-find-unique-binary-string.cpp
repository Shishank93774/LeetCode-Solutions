bool vis[17];

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        memset(vis, false, sizeof vis);
        const int n = nums.size();
        for(string s: nums){
            int num = 0;
            for(int i = n-1; i>=0; i--)
                if(s[i] == '1') num += (1<<(n-1-i));
            if(num < 17) vis[num] = true;
        }
        
        for(int i = 0; i<17; i++){
            if(!vis[i]){
                string ans;
                while(i){
                    if(i&1) ans += '1';
                    else ans += '0';
                    i >>= 1;
                }
                while(ans.size() < n) ans += '0';
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        return "-1";
    }
};