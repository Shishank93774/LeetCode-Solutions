class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<string> numbers;
        int fac = 1;
        for(int i = 1; i<=n; i++){
            fac *= i;
            numbers.push_back(to_string(i));
        }
        k--;
        fac /= n;
        while(true){
            int block = k/fac;
            ans += numbers[block];
            numbers.erase(numbers.begin() + block);
            if(numbers.size() == 0) break;
            k = k%fac;
            fac /= numbers.size(); 
        }
        return ans;
    }
};