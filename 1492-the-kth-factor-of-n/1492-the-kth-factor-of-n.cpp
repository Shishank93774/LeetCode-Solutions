class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facs;
        bool isPrfctSq = false;
        
        for(int x = 1; x*x<=n; x++) if(n%x == 0) {facs.push_back(x); isPrfctSq |= (x == n/x);}
        
        for(int i = facs.size() - (1 + isPrfctSq); i>=0; i--) facs.push_back(n/facs[i]);

        if(k > facs.size()) return -1;
        k--;
        return facs[k];
    }
};