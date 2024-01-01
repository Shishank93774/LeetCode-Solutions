class Solution {
    int n;
    vector<vector<int>> pre1, pre2;
    vector<int> eqPre;
    string s1, s2;
    
    bool chkPre(int a){
        if(a<0) return true;
        return (eqPre[a] == a+1);
    }
    
    bool chkSuf(int cd){
        if(cd >= n) return true;
        return ((eqPre[n-1] - (cd>0?eqPre[cd-1]:0)) == (n - cd));
    }
    
    bool isSame(int l, int r){
        if(l > r) return true;
        return (eqPre[r] - (l>0?eqPre[l-1]:0) == (r - l + 1));
    }
    
    bool canMakeSame(int l, int r){
        if(l > r) return true;
        for(int c = 0; c<26; c++)
            if(diffInPre1(l, r, c) != diffInPre2(l, r, c)) return false;
        return true;
    }
    
    int diffInPre1(int l, int r, int c){
        if(l > r) return 0;
        
        return ((r>=0?pre1[r][c]:0) - (l>0?pre1[l-1][c]:0)); 
    }
    
    int diffInPre2(int l, int r, int c){
        if(l > r) return 0;
        
        return ((r>=0?pre2[r][c]:0) - (l>0?pre2[l-1][c]:0));
    }
    
    bool _1_2(int l1, int r1, int l2, int r2){
        // l1.......r1....
        // ....l2.......r2
        
        vector<int> have1(26, 0);
        for(int c = 0; c<26; c++){
            have1[c] = diffInPre1(l1, r1, c);
            have1[c] -= diffInPre2(l1, l2-1, c);
            if(have1[c] < 0) return false;
        }
        
        vector<int> have2(26, 0);
        for(int c = 0; c<26; c++){
            have2[c] = diffInPre2(l2, r2, c);
            have2[c] -= diffInPre1(r1+1, r2, c);
            if(have2[c] < 0) return false;
            
            if(have1[c] != have2[c]) return false;
        }
        return true;
    }
    
    bool _2_1(int l1, int r1, int l2, int r2){
        // .....l1.......r1
        // l2........r2....
        
        vector<int> have2(26, 0);
        for(int c = 0; c<26; c++){
            have2[c] = diffInPre2(l2, r2, c);
            have2[c] -= diffInPre1(l2, l1-1, c);
            if(have2[c] < 0) return false;
        }
        
        vector<int> have1(26, 0);
        for(int c = 0; c<26; c++){
            have1[c] = diffInPre1(l1, r1, c);
            have1[c] -= diffInPre2(r2+1, r1, c);
            if(have1[c] < 0) return false;
            
            if(have1[c] != have2[c]) return false;
        }
        return true;
    }
    
    bool _1over2(int l1, int r1, int l2, int r2){
        // l1...............r1
        // ....l2........r2...
        
        int have;
        for(int c = 0; c<26; c++){
            have = diffInPre1(l1, r1, c);
            have -= diffInPre2(l1, l2-1, c);
            have -= diffInPre2(r2+1, r1, c);
            if(have != diffInPre2(l2, r2, c)) return false;
        }
        return true;
    }
    
    bool _2over1(int l1, int r1, int l2, int r2){
        // ....l1.......r1....
        // l2...............r2
        
        int have;
        for(int c = 0; c<26; c++){
            have = diffInPre2(l2, r2, c);
            have -= diffInPre1(l2, l1-1, c);
            have -= diffInPre1(r1+1, r2, c);
            if(have != diffInPre1(l1, r1, c)) return false;
        }
        return true;
    }
    
    void pre(){
        pre1.assign(n, vector<int>(26, 0));
        pre2.assign(n, vector<int>(26, 0));
        eqPre.resize(n);
        
        for(int i = 0; i<n; i++){
            for(int c = 0; c<26; c++){
                pre1[i][c] = ((s1[i] - 'a') == c);
                pre1[i][c] += (i?pre1[i-1][c]:0);
            }
            for(int c = 0; c<26; c++){
                pre2[i][c] = ((s2[i] - 'a') == c);
                pre2[i][c] += (i?pre2[i-1][c]:0);
            }
            
            eqPre[i] = (s1[i] == s2[i]);
            eqPre[i] += (i>0?eqPre[i-1]:0);
        }
    }
public:
    vector<bool> canMakePalindromeQueries(string &str, vector<vector<int>>& queries) {
        n = str.size();
        s1 = str.substr(0, n/2), s2 = str.substr(n/2);
        reverse(s2.begin(), s2.end());
        
        n >>= 1;
        pre();
        
        int q = queries.size();
        vector<bool> ans(q);
        int tn = n<<1;
        
        for(int i = 0; i<q; i++){
            int a = queries[i][0], b = queries[i][1];
            int c = queries[i][2], d = queries[i][3];
            int cd = tn - 1 - c, dd = tn - 1 - d;
            bool chk = true;
            int ll = min(a, dd);
            int rr = max(b, cd);
            chk &= chkPre(ll-1);
            chk &= chkSuf(rr+1);
            if((dd <= b and dd >= a) or (dd <= a and a <= cd)){ // overlap
                if(a < dd){
                    if(b < cd) chk &= _1_2(a, b, dd, cd);
                    else chk &= _1over2(a, b, dd, cd);
                }else if(a > dd){
                    if(b > cd) chk &= _2_1(a, b, dd, cd);
                    else chk &= _2over1(a, b, dd, cd);
                }else{
                    if(b < cd)
                        chk &= _2over1(a, b, dd, cd);
                    else if(b > cd)
                        chk &= _1over2(a, b, dd, cd);
                    else
                        chk &= _2over1(a, b, dd, cd);
                }
            }else{ // no overlap
                if(b < dd){
                    chk &= canMakeSame(a, b);
                    chk &= isSame(b+1, dd-1);
                    chk &= canMakeSame(dd, cd);
                }else{
                    chk &= canMakeSame(a, b);
                    chk &= isSame(cd+1, a-1);
                    chk &= canMakeSame(dd, cd);
                }
            }
            ans[i] = chk;
        }
        
        return ans;
        
    }
};