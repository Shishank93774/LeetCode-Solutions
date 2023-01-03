class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].length();
        int ans = 0;
        for(int i = 0; i<len; i++){
            char prv = strs[0][i];
            for(int j = 0; j<strs.size(); j++){
                if(prv > strs[j][i]){
                    ans++; break;
                }
                prv = strs[j][i];
            }
        }
        return ans;
    }
};