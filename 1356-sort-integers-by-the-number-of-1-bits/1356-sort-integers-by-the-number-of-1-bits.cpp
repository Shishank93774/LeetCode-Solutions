char set_bits(int x){
    char ans = 0;
    while(x>0){
        ans++;
        x &= (x-1);
    }
    return ans;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int a1, const int a2){
            char s1 = set_bits(a1), s2 = set_bits(a2);
            return s1==s2?a1<a2:s1<s2;
        });
        return arr;
    }
};