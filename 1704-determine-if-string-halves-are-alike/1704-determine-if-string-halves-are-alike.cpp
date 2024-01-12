string vowels = "aeiouAEIOU";
class Solution {
public:
    bool halvesAreAlike(string str) {
        int n = str.size();
        int i = 0, j = n/2;
        int a1 = 0, a2 = 0;
        while(j<n){
            if(vowels.find(str[i]) != vowels.npos) a1++;
            if(vowels.find(str[j]) != vowels.npos) a2++;
            i++; j++;
        }
        return a1 == a2;
    }
};