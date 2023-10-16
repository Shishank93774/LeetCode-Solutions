class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1, 1);
        for(int i = 0; i<rowIndex; i++){
            vector<int> next_row(cur.size() + 1, 0);
            for(int j = 0; j<cur.size(); j++){
                next_row[j] += cur[j];
                next_row[j+1] += cur[j];
            }
            cur = next_row;
        }
        
        return cur;
    }
};