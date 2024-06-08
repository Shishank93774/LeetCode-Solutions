class Solution {
public:
    vector<int> queryResults(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        unordered_map<int, int> colors;
        unordered_map<int, int> balls;
        for(auto v: queries){
            int ball = v[0], color = v[1];
            
            if(balls.find(ball) != balls.end()){
                int earlier_color = balls[ball];
                if(--colors[earlier_color] == 0)
                    colors.erase(earlier_color);
            }
            balls[ball] = color;
            colors[color]++;

            ans.push_back(colors.size());
        }
        
        return ans;
    }
};