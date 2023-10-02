class Solution {
public:
    bool winnerOfGame(const string &colors) {
        int n = colors.size();
        int canA = 0, canB = 0;
        for(int i = 1; i+1<n; i++){
            if(colors[i-1] == colors[i] and colors[i] == colors[i+1]){
                canA += (colors[i] == 'A');
                canB += (colors[i] == 'B');
            }
        }
        
        return canA > canB;
    }
};