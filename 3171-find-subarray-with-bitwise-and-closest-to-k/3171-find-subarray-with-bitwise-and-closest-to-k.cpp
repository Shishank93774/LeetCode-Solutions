struct SPT{ // 0-indexed
    vector<vector<int> > st;
    vector<int> lg;
    SPT(vector<int> &a) : st(__lg(a.size()) + 1, a), lg(a.size() + 1, 0) 
    {
        int n = a.size();
        for(int i = 2; i<=n; i++) lg[i] = lg[i/2] + 1;
        int mxlg = lg[n];
        for(int k = 1, len = 1; k <= mxlg; ++k, len <<= 1)
            for(int i = 0; i + 2 * len <= n; ++i)
                st[k][i] = (st[k-1][i] & st[k-1][i+len]); // CHANGE HERE
    }
    int query(int a, int b){
        int k = lg[b-a+1], len = 1ll<<k;

        return (st[k][a] & st[k][b-len+1]); // CHANGE HERE
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& arr, int k) {
        int n = arr.size();
        
        int ans =1e9;
        
        set<int> st;
        
        for(int i = 0; i<n; i++){
            set<int> tmp;
            for(int v: st){
                tmp.insert(v&arr[i]);
            }
            tmp.insert(arr[i]);
            for(int v: tmp) ans = min(ans, abs(v-k));
            swap(tmp, st);
        }
        
        return ans;
    }
};