class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
    }
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string> st;
        for(string str: ideas) st.insert(str);
        vector<vector<int> > freq(26, vector<int>(26, 0));
        for(string str: ideas){
            for(char ch = 'a'; ch <= 'z'; ch++){
                swap(str[0], ch);
                if(st.find(str) == st.end()) freq[str[0] - 'a'][ch - 'a']++;
                swap(str[0], ch);
            }
        }
        for(int i = 0; i<26; i++){
            for(int j = i+1; j<26; j++) ans = ans + 2ll*freq[i][j]*freq[j][i];
        }
        return ans;
    }
};