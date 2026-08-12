class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freqS;
        map<char, int> freqT;
        if(s.length() != t.length()) return false;
        for(int i=0; i<s.length(); i++){
            freqS[s[i]]++;
            freqT[t[i]]++;
        }
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(freqS[c] != freqT[c]){
                return false;
            }
        }
        return true;
        // better we creattre array of characters and then first increatment and next loop decrement, if any pending then false;
    }
};
