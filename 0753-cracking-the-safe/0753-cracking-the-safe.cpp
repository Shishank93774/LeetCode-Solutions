const int N = 4, K = 11, MAX = 4100;
vector<int> adj[MAX];
int vis[MAX];
int n, k, tot;
string full;
bool found;

int btoi(const string &s){
    int res = 0, sz = s.size(), f = 1;
    
    while(sz--){
        int v = s[sz] - '0';
        res += v*f;
        f *= k;
    }
    return res;
}

void to_base(int v, string &res){
    
    while(v>0){
        int rem = v%k;
        char ch = ('0' + rem);
        res += ch;
        v /= k;
    }
    while(res.size() < n) res += '0';
    reverse(res.begin(), res.end());
}

void dfs(int u, string &cur, int cnt){
    if(found) return;
    vis[u] = true;
    string bin_rep;
    to_base(u, bin_rep);
    if(cnt == tot-1){
        found = true;
        cur += bin_rep;
        full = cur;
        return;
    }

    for(int v: adj[u]){
        if(!vis[v]){
            cur += bin_rep;
            dfs(v, cur, cnt+1);
            for(int i = 0; i<n; i++) cur.pop_back();
        }
    }
    vis[u] = false;
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r){
   uniform_int_distribution<int> dist(l, r);
   return dist(rnd);
}

class Solution {
public:
    string crackSafe(int nn, int kk) {
        n = nn;
        k = kk;
        for(int i = 0; i<MAX; i++) adj[i].clear(), vis[i] = false;
        full = "";
        found = false;
        tot = pow(k, n);
        
        for(int i = 0; i<tot; i++){
            string rep;
            to_base(i, rep);
            
            reverse(rep.begin(), rep.end());
            rep.pop_back();
            reverse(rep.begin(), rep.end());
            for(int j = 0; j<k; j++){
                char ch = ('0' + j);
                rep.push_back(ch);
                int v = btoi(rep);
                rep.pop_back();
                adj[i].push_back(v);
            }
        }
        string cur;
        dfs(0, cur, 0);
        string ans;
        int f = 1;
        for(int i = 0; i<full.size(); i+=f){
            ans += full[i];
            if(i >= n-1)
                f = n;
        }
        return ans;       
    }
};