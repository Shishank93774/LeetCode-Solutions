struct point{
    char c;
    int pos;
};

struct comp{
    bool operator()(point &p1, point &p2){
        if(p1.c == p2.c) return p1.pos < p2.pos;
        return p1.c > p2.c;
    }
};

class Solution {
public:
    string clearStars(string &str) {
        int n = str.size();
        
        priority_queue<point, vector<point>, comp> pqu;
        
        for(int i = 0; i<n; i++){
            if(str[i] == '*'){
                if(!pqu.empty()) pqu.pop();
            }else{
                pqu.push({str[i], i});
            }
        }
        vector<point> v;
        while(!pqu.empty()){
            v.push_back(pqu.top()); pqu.pop();
        }
        string ans;
        sort(v.begin(), v.end(), [](point &p1, point &p2){
            return p1.pos < p2.pos;
        });
        
        for(auto vk: v){
            ans += vk.c;
        }
        return ans;
    }
};