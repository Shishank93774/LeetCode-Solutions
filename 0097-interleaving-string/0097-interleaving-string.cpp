class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        if(a.size() + b.size() != c.size()) return false;
        vector<int> down(b.size()+1), cur(b.size()+1);
        for(int i = a.size(); i>=0; i--){
            for(int j = b.size(); j>=0; j--){
                if(i+j == c.size()){
                    cur[j] = true;
                }else{
                    int ans = false;
                    if(a[i] == c[i+j] and b[j] == c[i+j]){
                        ans = down[j] | cur[j+1];
                    }else if(a[i] == c[i+j]){
                        ans = down[j];
                    }else if(b[j] == c[i+j]){
                        ans = cur[j+1];
                    }else ans = false;
                    cur[j] = ans;
                }
            }
            down = cur;
        }
        return down[0];
    }
};