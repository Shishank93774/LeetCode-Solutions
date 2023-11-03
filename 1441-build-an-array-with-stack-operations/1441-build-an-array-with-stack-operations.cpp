class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 1;
        for(int x: target){
            if(cur == x) ans.push_back("Push");
            else{
                int cnt = 0;
                while(cur != x) cur++, cnt++, ans.push_back("Push");
                while(cnt--) ans.push_back("Pop");
                ans.push_back("Push");
            }
            cur++;
        }
        return ans;
    }
};