class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pqu(stones.begin(), stones.end());
        while(pqu.size() > 1){
            int f = pqu.top(); pqu.pop();
            int s = pqu.top(); pqu.pop();
            if(f-s) pqu.push(f-s);
        }
        pqu.push(0);
        return pqu.top();
    }
};