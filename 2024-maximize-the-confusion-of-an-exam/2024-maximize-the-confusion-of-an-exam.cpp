class Solution {
public:
    int maxConsecutiveAnswers(string &str, int k) {
        int a1 = 0, a2 = 0, i = 0, j = 0, ans = 0, n = str.size();
        while(i<n and j<n){
            str[j]=='T'?a1++:a2++;
            int mn = min(a1, a2);
            if(mn <= k){
                ans = max(ans, j-i+1);
            }else{
                while(mn > k){
                    str[i++]=='T'?a1--:a2--;
                    mn = min(a1, a2);
                }
            }
            j++;
        }
        return ans;
        // int a1 = 0, a2 = 0, i = 0, j = 0, cur = 0, n = str.size();
        // while(i<n and j<n){
        //     while(j<n and cur + (str[j] == 'F') <=k){
        //         cur += (str[j++] == 'F');
        //     }
        //     a1 = max(a1, j-i);
        //     cur -= (str[i++] == 'F');
        // }
        // i = 0, j = 0, cur = 0;
        // while(i<n and j<n){
        //     while(j<n and cur + (str[j] == 'T') <=k){
        //         cur += (str[j++] == 'T');
        //     }
        //     a2 = max(a2, j-i);
        //     cur -= (str[i++] == 'T');
        // }
        // return max(a1, a2);
    }
};