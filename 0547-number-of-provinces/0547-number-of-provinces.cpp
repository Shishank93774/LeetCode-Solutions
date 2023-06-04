#define LIM 200

int parent[LIM], Rank[LIM];

void pre(){
     for(int i = 0; i<LIM; i++){
         parent[i] = i;
         Rank[i] = 1;
     }
}

int find(int x){
    if(x == parent[x]) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int u, int v){
     int rootU = find(u);
     int rootV = find(v);
     if(rootU == rootV)return;
     if(Rank[rootU] > Rank[rootV])
         parent[rootV] = rootU;
     else if(Rank[rootV] > Rank[rootU])
         parent[rootU] = rootV;
     else{
         parent[rootV] = rootU;
         Rank[rootU]++;
     }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        pre();
        set<int> st;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){
                    Union(i, j);
                }
            }
        }
        for(int i = 0; i<n; i++)st.insert(find(i));
        return st.size();
    }
};