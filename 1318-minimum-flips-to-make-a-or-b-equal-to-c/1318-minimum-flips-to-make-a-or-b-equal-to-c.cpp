class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a>0 or b>0 or c>0){
            int bita = a%2, bitb = b%2, bitc = c%2;
            if(bitc){
                if(bita or bitb){}
                else ans++;
            }else{
                ans += (bita+bitb);
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return ans;
    }
};