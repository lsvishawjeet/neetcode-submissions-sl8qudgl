class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for(auto c:t){
            mp[c]++;
        }
        int l = 0;
        int r = 0;
        int startIndex = -1;
        int minLen = INT_MAX;
        int count = 0;
        
        while(r<s.length()){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;

            while(count==t.length() && l<s.length()){
                int newLen = r-l+1;
                if(newLen < minLen){
                    minLen = newLen;
                    startIndex = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }

        return startIndex==-1?"":s.substr(startIndex, minLen);
    }
};
