class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = n;
        
        for(int v = 1; v<=6; v++){
            int cur = 0;
            bool chk = true;
            for(int i = 0; i<n; i++){ // cnt for top
                if(v != tops[i]){
                    if(v == bottoms[i]) cur++;
                    else{
                        chk = false;
                        break;
                    }
                }
            }
            if(chk) ans = min(ans, cur);
            cur = 0;
            chk = true;
            for(int i = 0; i<n; i++){ // cnt for top
                if(v != bottoms[i]){
                    if(v == tops[i]) cur++;
                    else{
                        chk = false;
                        break;
                    }
                }
            }
            if(chk) ans = min(ans, cur);
        }
        
        return ans==n?-1:ans;
    }
};