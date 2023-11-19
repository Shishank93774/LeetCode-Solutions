const int mod = 1e9+7;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        
        long long A = a%mod, B = b%mod;
        for(int bit = n-1; bit>=0; bit--){
            long long abit = (a&(1ll<<bit)), bbit = (b&(1ll<<bit));
                
            if(abit and bbit){

            }else if(abit){
                if(a >= b){
                    a ^= (1ll<<bit);
                    b ^= (1ll<<bit);
                }    
            }else if(bbit){
                if(b >= a){
                    a ^= (1ll<<bit);
                    b ^= (1ll<<bit);
                }
            }else{
                a |= (1ll<<bit);
                b |= (1ll<<bit);
            }
            A = a%mod;
            B = b%mod;
        }
        
        return (A*B)%mod;
        
    }
};