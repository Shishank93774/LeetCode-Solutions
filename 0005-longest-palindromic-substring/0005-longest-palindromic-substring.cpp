class Solution {
    int chk(string str, int len){
        for(int s = 0; s+len <= str.size(); s++){
            bool chk = true;
            int l = s, r = s+len-1;
            while(l<=r){
                if(str[l] != str[r]) {chk = false; break;}
                l++; r--;
            }
            if(chk) return s;
        }
        return -1;
    }
public:
    string longestPalindrome(string str) {
        int mx = 0, n = str.size();
        int strt = 0;
        for(int parity: {0, 1}){  // EVEN LEN or ODD LEN
            int l = 1, r = n;
            if(l%2 != parity) l++;
            if(r%2 != parity) r--;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(mid%2 != parity) mid--;
                int t = chk(str, mid);
                if(t != -1){
                    if(mx < mid){
                        mx = mid;
                        strt = t;
                    }
                    l = mid + 2;
                }else{
                    r = mid - 2;
                }
            }
        }
        return str.substr(strt, mx);
    }
};