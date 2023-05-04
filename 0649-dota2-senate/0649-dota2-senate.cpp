class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rqu, dqu;
        int n = senate.size();
        for(int i = 0; i<n; i++){
            if(senate[i] == 'R') rqu.push(i);
            else dqu.push(i);
        }
        while(rqu.size() and dqu.size()){
            int f1 = rqu.front(); rqu.pop();
            int f2 = dqu.front(); dqu.pop();
            if(f1 < f2){
                rqu.push(n+f1);
            }else{
                dqu.push(n+f2);
            }
        }
        if(dqu.size()) return "Dire";
        return "Radiant";
    }
};