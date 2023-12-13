class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1, 1);
        for(int i = 0; i<rowIndex; i++){
            vector<int> next_row(cur.size() + 1, 0);
            for(int j = cur.size()-1; j>0; j--){
                cur[j] += cur[j-1];
            }
            cur.push_back(1);
        }
        
        return cur;
    }
};