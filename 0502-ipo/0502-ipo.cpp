struct point{
  int p, c;  
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<point> arr;
        int n = profits.size();
        for(int i = 0; i<n; i++) arr.push_back({profits[i], capital[i]});
        sort(arr.begin(), arr.end(), [](const point p1, const point p2){
            return p1.c == p2.c?p1.p > p2.p : p1.c < p2.c;
        });
        priority_queue<int> pqu;
        int used = 0, i = 0;
        while(used < k){
            while(i<n and arr[i].c <= w){
                pqu.push(arr[i].p);
                i++;
            }
            if(pqu.empty()) break;
            w += pqu.top(); pqu.pop(); used++;
        }
        return w;
    }
};