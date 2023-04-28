class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> vis(n, false);
        int ans = 0;
        
        auto isSimilar = [&](int i, int j) ->bool{
            string s = strs[i], t = strs[j];
            if(s.size() != t.size()) return false;
            int sz = s.size(), diff = 0;
            for(int i = 0; i<sz; i++){
                diff += (s[i] != t[i]);
                if(diff > 2) return false;
            }
            return (diff == 0 or diff == 2);
        };
        
        auto dfs = [&](int src, auto &&dfs) ->void {
            if(vis[src]) return;
            vis[src] = true;
            for(int i = 0; i<n; i++) if(i != src and !vis[i] and isSimilar(src, i)) dfs(i, dfs);
        };
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, dfs);
            }
        }
        return ans;
    }
};