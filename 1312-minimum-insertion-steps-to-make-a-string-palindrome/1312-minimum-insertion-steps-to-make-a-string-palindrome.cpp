class Solution {
public:
    int minInsertions(string &str) {
        
        int n = str.size();
        vector<int> down(n, 1e9), cur(n, 1e9);
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(i>=j) cur[j] = 0;
                else if(i+1 == j) cur[j] = (str[i] != str[j]);
                else{
                    if(str[i] == str[j]) cur[j] = (i+1<n and j-1>=0)?down[j-1]:1e9;
                    else cur[j] = 1 + min((i+1<n)?down[j]:0, (j-1>=0)?cur[j-1]:0);
                }
            }
            down = cur;
        }
        
        return down[n-1];
    }
};