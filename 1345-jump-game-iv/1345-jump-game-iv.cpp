class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        vector<bool> vis(n, false); 
        queue<int> qu; 
        qu.push(0);
        int ans = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            while(sz--){
                int f = qu.front(); qu.pop();
                if(f == n-1) return ans;
                if(vis[f]) continue; vis[f] = true;
                mp[arr[f]].push_back(f+1); mp[arr[f]].push_back(f-1);
                for(int nbr: mp[arr[f]]){
                    if(nbr<0 or nbr>=n) continue;
                    qu.push(nbr);
                }
                mp[arr[f]].clear();
            }
            ans++;
        }
        return 0;
    }
};