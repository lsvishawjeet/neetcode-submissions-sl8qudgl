class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> freq;
        int l=0;
        int r=0;
        int maxLen = 0;
        while(r < s.length()){
            if(freq[s[r]] > 0){
                while(freq[s[r]] > 0){
                    freq[s[l]]--;
                    l++;
                }
            }
            maxLen = max(maxLen, r-l+1);
            freq[s[r]]++;
            r++;
        }
        return maxLen;
    }
};
