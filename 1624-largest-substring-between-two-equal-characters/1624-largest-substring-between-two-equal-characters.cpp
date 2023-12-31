class Solution {
public:
    int maxLengthBetweenEqualCharacters(const string &str) {
        int firstOcc[26];
        memset(firstOcc, -1, sizeof firstOcc);
        int n = str.size();
        int ans = -1;
        for(int i = 0; i<n; i++){
            int c = str[i] - 'a'; 
            if(firstOcc[c] != -1){
                ans = max(ans, i - firstOcc[c] - 1);
            }else{
                firstOcc[c] = i;
            }
        }
        return ans;
    }
};