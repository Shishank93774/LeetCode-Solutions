class Solution {
public:
    int minMovesToMakePalindrome(const string &str) {
        int mn = INT_MAX;
        int n = str.size();
        char req;
        if(n == 1 or n == 2) return 0;
        int ans = 0;
        // cout<<str<<"\n";
        int lIdx = -1, rIdx = -1;
        for(char ch = 'a'; ch <= 'z'; ch++){
            int l = 0, r = n-1;
            while(l<=r and str[l] != ch) l++;
            if(l >= n) continue; // not in the string.
            while(r>=l and str[r] != ch) r--;
            if(l == r) continue; // odd oned
            if(mn > l + (n-1-r)){
                mn = l + (n-1-r);
                req = ch;
                lIdx = l, rIdx = r;
            }
        }
        // cout<<req<<" "<<mn<<"\n\n";
        if(lIdx == -1) return ans;
        ans = mn;
        if(lIdx == 0 and rIdx == n-1){
            ans += minMovesToMakePalindrome(str.substr(1, n-2));
        }else if(lIdx == 0){
            ans += minMovesToMakePalindrome(str.substr(1, rIdx-1)+str.substr(rIdx+1));
        }else if(rIdx == n-1){
            ans += minMovesToMakePalindrome(str.substr(0, lIdx)+str.substr(lIdx+1, rIdx-lIdx-1));
        }else{
            ans += minMovesToMakePalindrome(str.substr(0, lIdx)+str.substr(lIdx+1, rIdx-lIdx-1)+str.substr(rIdx+1));
        }
        return ans;
    }
};