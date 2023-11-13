class Solution {
    bool isVowel(char ch){
        switch(ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }
public:
    string sortVowels(string str) {
        vector<int> vowIdxs;
        int n = str.size();
        for(int i = 0; i<n; i++)
            if(isVowel(str[i])) vowIdxs.push_back(i);
        sort(vowIdxs.begin(), vowIdxs.end(), [&](int a, int b){
           return str[a] < str[b]; 
        });
        string ans;
        int j = 0;
        for(int i = 0; i<n; i++){
            if(isVowel(str[i])){
                ans += str[vowIdxs[j++]];
            }else{
                ans += str[i];
            }
        }
        return ans;
    }
};