class Solution {
public:
    int maxVowels(string str, int k) {
        int ans = 0;
        int i = 0, j = 0, n = str.size();
        int cur = 0;
        
        auto isVowel = [&](char ch)->bool {
            if(ch == 'a') return true;
            else if(ch == 'e') return true;
            else if(ch == 'i') return true;
            else if(ch == 'o') return true;
            else if(ch == 'u') return true;
            return false;
        };
        
        while(j<n){
            while(j<n and j-i+1<=k) cur += (isVowel(str[j++]));
            ans = max(ans, cur);
            cur -= (isVowel(str[i++]));
        }
        return ans;
    }
};