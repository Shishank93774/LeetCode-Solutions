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
        
        SPT st(arr);
        
        int ans = 1e9;
        
        for(int i = 0; i<n; i++){
            ans = min(ans, abs(arr[i] - k));
            int l = i, r = n-1;
            int mn = 1e9;
            while(l<=r){
                int m1 = l + (r - l)/3;
                int m2 = r - (r - l)/3;
                
                int f1 = abs(k - st.query(i, m1));
                int f2 = abs(k - st.query(i, m2));
                
                mn = min({mn, f1, f2});
                if(f1 < f2)
                    r = m2 - 1;
                else
                    l = m1 + 1;
            }
            
            l = i, r = n-1;
            
            while(l<=r){
                int m1 = l + (r - l)/3;
                int m2 = r - (r - l)/3;
                
                int f1 = abs(k - st.query(i, m1));
                int f2 = abs(k - st.query(i, m2));
                
                mn = min({mn, f1, f2});
                if(f1 <= f2)
                    r = m2 - 1;
                else
                    l = m1 + 1;
            }
            ans = min(ans, mn);
            
        }
        return ans;
    }
};