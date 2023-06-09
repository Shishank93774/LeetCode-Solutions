class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1, ans = 0, mid;
        auto bs = [&]()->char{
            while(l<=r){
                mid = l + (r-l)/2;
                if(letters[mid] > target) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            return letters[ans];
        };
        return bs();
    }
};