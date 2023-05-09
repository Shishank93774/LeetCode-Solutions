class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int rStrt = 0, rEnd = n-1, cStrt = 0, cEnd = m-1;
        vector<int> ans;
        int cnt = 0;
        while(rStrt<=rEnd and cStrt <= cEnd){
            for(int c = cStrt; c<=cEnd; c++){
                ans.push_back(mat[rStrt][c]);
            }
            rStrt++;
            if(rStrt>rEnd)break;
            for(int r = rStrt; r<=rEnd; r++){
                ans.push_back(mat[r][cEnd]); 
            }
            cEnd--;
            if(cStrt>cEnd)break;
            for(int c = cEnd; c>=cStrt; c--){
                ans.push_back(mat[rEnd][c]);
            }
            rEnd--;
            if(rStrt>rEnd)break;
            for(int r = rEnd; r>=rStrt; r--){
                ans.push_back(mat[r][cStrt]);
            }
            cStrt++;
        }
        return ans;
    }
};