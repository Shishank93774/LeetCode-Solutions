class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto bs = [&]()->char{
            int l = 0, r = letters.size() - 1;
            int ans = 0;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(letters[mid] > target) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            return letters[ans];
        };
        return bs();
    }
};