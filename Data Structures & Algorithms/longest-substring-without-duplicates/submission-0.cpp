class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> lastIndex;

        int r = 0;
        int l = 0;
        int maxLength = 0;
        while(r < s.length()){
            if(lastIndex.find(s[r]) != lastIndex.end()){
                l = max(l, lastIndex[s[r]] + 1);
            }
            lastIndex[s[r]] = r;
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};
