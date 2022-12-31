struct process{
    int id, at, bt;
};

struct comp{
    bool operator()(process p1, process p2){
        if(p1.at == p2.at){
            return p1.bt < p2.bt;   
        }
        return p1.at < p2.at;
    }
};

struct comp2{
    bool operator()(process p1, process p2){
        if(p1.bt == p2.bt){
            return p1.id > p2.id;   
        }
        return p1.bt > p2.bt;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<process> arr;
        int cur = 0, n = tasks.size();
        for(auto v: tasks){
            process P = {cur++, v[0], v[1]};
            arr.push_back(P);
        }
        sort(arr.begin(), arr.end(), comp());
        long long curT = arr[0].at + arr[0].bt;
        vector<int> ans;
        ans.push_back(arr[0].id);
        priority_queue<process, vector<process>, comp2> pqu;
        int curP = 1;
        while(curP < n){
            while(curP < n and arr[curP].at <= curT){
                pqu.push(arr[curP]);
                curP++;
            }
            if(pqu.empty()){
                pqu.push(arr[curP]);
                curT = arr[curP].at; 
                curP++;  
            }
            process tp = pqu.top(); pqu.pop();
            ans.push_back(tp.id);
            curT += tp.bt;
        }
        while(!pqu.empty()){
            process tp = pqu.top(); pqu.pop();
            ans.push_back(tp.id);
            curT += tp.bt;
        }
        return ans;
    }
};