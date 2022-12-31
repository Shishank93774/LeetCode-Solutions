class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        
        long ans = 0;
        bool nond = false, isNeg = false;
        int i = 0;
        while(i<n and str[i] == ' ')i++;
        while(i<n){
            if(str[i] >= '0' and str[i] <= '9'){
                nond = true;
                int t = str[i] - '0';
                if(isNeg) t = 0-t;
                ans = ans*10 + t;
                if(ans >= INT_MAX) return INT_MAX;
                if(ans <= INT_MIN) return INT_MIN;
            }else if(str[i] == '-'){
                if(nond) break;
                isNeg = true;
                nond = true;                
            }else if(str[i] == '+'){
                if(nond) break;
                nond = true;
            }else{
                nond = true;
                break;
            }
            i++;
        }
        return ans;
    }
};