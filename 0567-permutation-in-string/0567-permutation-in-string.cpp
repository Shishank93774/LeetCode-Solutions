class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> req, cur;
        for(char c: s1) req[c]++;
        int n = s1.size(), m = s2.size();
        for(int i = 0; i<min(n, m); i++) cur[s2[i]]++;
        bool ok = true;
        if(req.size() == cur.size()){
            for(auto it: req){
                if(req[it.first] != cur[it.first]){
                    ok = false;
                }
            }
            if(ok) return true;
        }
        for(int i = n; i<m; i++){
            cur[s2[i-n]]--;
            if(cur[s2[i-n]] == 0) cur.erase(s2[i-n]);
            cur[s2[i]]++;
            bool ok = true;
            if(req.size() == cur.size()){
                for(auto it: req){
                    if(req[it.first] != cur[it.first]){
                        ok = false; break;
                    }
                }
                if(ok){
                    return true;
                }
            }
        }
        return false;
    }
};