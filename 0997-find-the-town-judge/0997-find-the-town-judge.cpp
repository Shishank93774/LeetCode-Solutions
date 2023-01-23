class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n+1, 0), outDeg(n+1, 0);
        for(int i = 0; i<trust.size(); i++){
            outDeg[trust[i][0]]++;
            inDeg[trust[i][1]]++;
        }
        int ans = -1;
        for(int i = 1; i<=n; i++){
            if(inDeg[i] == n-1 and outDeg[i] == 0){
                if(ans != -1) return -1;
                ans = i;
            } 
        }
        return ans;
    }
};