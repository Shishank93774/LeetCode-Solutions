class Solution {
    bool isSubSeq(const string &sub, const string &sup){
        int i = 0, j = 0;
        while(i<sub.size() and j<sup.size()){
            if(sub[i] == sup[j]) i++;
            j++;
        }
        return (i==sub.size());
    }
public:
    string findLongestWord(const string &sup, vector<string>& dictionary) {
        string ans = "{";
        for(string &sub: dictionary){
            if(isSubSeq(sub, sup) and (ans.size() < sub.size() or (ans.size() == sub.size() and ans > sub))) ans = sub; 
        }
        if(ans == "{") ans.clear();
        return ans;
    }
};