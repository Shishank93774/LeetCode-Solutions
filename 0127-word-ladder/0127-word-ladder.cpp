class Solution {
public:
    int ladderLength(const string &beginWord, const string &endWord, const vector<string> &wordList) {
        int n = wordList.size();
        vector<vector<int> > adj(n+2);
        
        auto isNext = [](const string &s1, const string &s2)->bool{
            int n = s1.size(), m = s2.size();
            if(n != m or s1 == s2) return false;
            int chg = 0;
            for(int i = 0; i<n; i++){
                if(s1[i] != s2[i]) chg++;
                if(chg > 1) return false;
            }
            return true;
        };
        int src = 0, dest = -1;
        for(int i = 0; i<n; i++){
            if(beginWord == wordList[i]) src = i+1;
            if(endWord == wordList[i]) dest = i+1;
        }
        if(dest == -1) return 0;
        
        if(src == 0){    
            for(int i = 0; i<n; i++){
                if(isNext(beginWord, wordList[i])){
                    adj[0].push_back(i+1);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isNext(wordList[i], wordList[j])){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        queue<int> qu;
        qu.push(src);
        vector<int> vis(n+2, false);
        int d = 1;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int f = qu.front(); qu.pop();
                if(f == dest) return d;
                if(vis[f]) continue;
                vis[f] = true;
                for(int nbr: adj[f]){
                    if(vis[nbr]) continue;
                    qu.push(nbr);
                }
            }
            d++;
        }
        return 0;
    }
};