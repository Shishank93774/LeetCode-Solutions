class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if(s1 == s2) return 0;
        
        int i = 0;
        while(s1[i] == s2[i]) i++;
        
        vector<int> good;
        
        for(int j = i+1; j<s1.size(); j++){
            if((s1[j] == s2[j]) or (s1[j] != s2[i])) continue;
            
            good.push_back(j);
            
            if(s1[i] == s2[j]){
                swap(s1[i], s1[j]);
                
                return 1 + kSimilarity(s1.substr(i+1), s2.substr(i+1));
            }
        }
        int ans = s1.size()-1;
        bool used[6] = {};
        for(int j: good){
            if(used[s2[j] - 'a']) continue;
            used[s2[j] - 'a'] = true; 
            swap(s1[i], s1[j]);
            ans = min(ans, 1 + kSimilarity(s1.substr(i+1), s2.substr(i+1)));
            swap(s1[i], s1[j]);
        }
        
        return ans;
    }
};