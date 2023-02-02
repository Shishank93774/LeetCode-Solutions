vector<int> pos(26);
vector<string> arr;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        arr = words; for(int i = 0; i<26; i++) pos[order[i] - 'a'] = i;
        sort(arr.begin(), arr.end(), [&](const string &s1, const string &s2){
            for(int i = 0; i<min(s1.size(), s2.size()); i++) if(pos[s1[i] - 'a'] > pos[s2[i] - 'a']) return false; else if(pos[s1[i] - 'a'] < pos[s2[i] - 'a']) return true;
            if(s1.size()<=s2.size()) return true; return false;
        });
        for(int i = 0; i<words.size(); i++) if(words[i] != arr[i]) return false;
        return true;
    }
};