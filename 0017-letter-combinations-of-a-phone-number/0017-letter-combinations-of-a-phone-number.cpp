string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string &str) {
        
        vector<string> ans;
        int n = str.size();
        if(n == 0) return ans;
        auto rec = [&](int i, string till, auto &&rec)->void{
            if(i == n){
                ans.push_back(till);
                return;
            }
            
            for(char ch: arr[str[i] - '0']){
                rec(i+1, till+ch, rec);
            }
        };
        rec(0,"",rec);
        return ans;
    }
};