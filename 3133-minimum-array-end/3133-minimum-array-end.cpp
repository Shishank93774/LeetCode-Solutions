#define ll long long

class Solution {
    void f(ll x, vector<int> &rep, ll &blk){
        int pos = 0;
        while(x){
            if((x&1) == 0){
                rep[pos] = 0;
                blk <<= 1;
            }else{
                rep[pos] = 1;
            }
            x >>= 1;
            pos++;
        }
    }
public:
    ll minEnd(int n, int x) {
        ll ans = 0;
        n--;
        
        vector<int> rep(64, 0);
        ll blk = 1;
        f(x, rep, blk);
        
        int quo = n/blk;
                
        int lidx = 0;
        for(int i = 0; i<64; i++){
            if(rep[i]){
                lidx = i+1;
            }
        }
        
        vector<int> repq(64, 0);
        ll p = 0;
        f(quo, repq, p);
        
        int pos = 0;
        while(quo){
            rep[lidx++] = repq[pos++];
            quo >>= 1;
        }
             
        ll rem = n%blk;
        
        vector<int> rep2(64, 0);
        ll kk = 0;
        f(rem, rep2, kk);
        
        
        lidx = -1;
        for(int i = 0; i<64; i++){
            if(rep2[i]){
                lidx = i;
            }
        }
        
        int j = 0;
        for(int i = 0; i<64 and (lidx>=0); i++){
            if(rep[i] == 0){
                rep[i] = rep2[j++];
                lidx--;
            }
        }
        
        for(int i = 0; i<64; i++){
            if(rep[i]){
                ans += (1ll<<i);
            }
        }
        
        return ans;

        
    }
};