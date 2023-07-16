class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> mp;
        for(int i = 0; i<req_skills.size(); i++) mp[req_skills[i]] = i;
        
        int skills_req = ((1<<(req_skills.size())) - 1);
        
        vector<int> peopleSkills(people.size());
        for(int i = 0; i<people.size(); i++){
            int rep = 0;
            for(auto skill: people[i]){
                rep = (rep | (1<<mp[skill]));
            }
            peopleSkills[i] = rep;
        }
        
        int mn = 1e9+7;
        vector<int> aa;
        vector<vector<int> > dp(61, vector<int>(1<<16, -1));
        
        
        auto rec = [&](int i, int req, vector<int> &people_req, auto &&rec)->void{
            if(req == 0) {
                if(people_req.size() < mn){
                    mn = people_req.size();
                    aa = people_req;
                }               
                return;
            }
            if(i == peopleSkills.size()) return;
            
            if(dp[i][req] != -1 and dp[i][req] <= people_req.size()) return;

            // take
            int skill = peopleSkills[i];
            int newReq = 0;
            for(int bit = 0; bit<req_skills.size(); bit++){
                bool bitreq = (req&(1<<bit));
                bool bithas = (skill&(1<<bit));
                if(bitreq and !bithas) newReq = (newReq | (1<<bit));
            }
            if(req != newReq){
                people_req.push_back(i);
                rec(i+1, newReq, people_req, rec);
                people_req.pop_back();
            }
            
            // not-take
            rec(i+1, req, people_req, rec);
            
            if(people_req.size() > 0) dp[i][req] = people_req.size();
        };
        
        vector<int> people_req;
        
        // cout<<rec(0, skills_req, people_req, rec)<<" ";
        rec(0, skills_req, people_req, rec);

        // cout<<"\n";

        // return {};
        return aa;
    }
};