class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        });
        int count=1, n = p.size();
        int x=p[0][1];
        for(int i=1;i<n;i++)
        {
            if(p[i][0]>x)
            {
                 x=p[i][1];
                 count++ ;
            }
           
        }
        
        return count ;
    }
};