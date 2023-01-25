class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        queue<int> qu;
        vector<int> dist1(n, -1);
        qu.push(node1);
        int d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz-- ){
                int f = qu.front(); qu.pop();
                if(dist1[f] != -1) continue;
                dist1[f] = d;
                if(edges[f] != -1) qu.push(edges[f]);
            }
            d++;
        }
        qu = queue<int>();
        vector<int> dist2(n, -1);
        qu.push(node2);
        d = 0;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz-- ){
                int f = qu.front(); qu.pop();
                if(dist2[f] != -1) continue;
                dist2[f] = d;
                if(edges[f] != -1) qu.push(edges[f]);
            }
            d++;
        }
        int mnDist = INT_MAX, ans = INT_MAX;
        for(int i = 0; i<n; i++) if(dist1[i] >=0 and dist2[i] >= 0 and mnDist > max(dist1[i], dist2[i])) ans = i, mnDist =  max(dist1[i], dist2[i]);
        return ans==INT_MAX?-1:ans;
    }
};