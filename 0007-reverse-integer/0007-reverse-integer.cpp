class Solution {
public:
    int reverse(int x) {
        bool neg = x<0;
        unsigned num = abs(x);
        unsigned ans = 0;
        while(num){
            if(ans > (INT_MAX - num%10)/10) return 0;
            ans = ans*10 + num%10;
            num /=10;
        }
        return neg?-ans:ans;
    }
};