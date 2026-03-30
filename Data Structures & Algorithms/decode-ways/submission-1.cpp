class Solution {
public:
    int ways(string s, int index){
        if(index == s.length()) return 1;
        if(index >= s.length()) return 0;
        if(s[index] == '0') return 0;

        int res = ways(s, index+1);
        if(s[index]=='1' || s[index]=='2' && s[index+1]<='6'){
            res += ways(s, index+2);
        }
        return res;
    }
    int numDecodings(string s) {
        // algorithm
        // take one and take two
        /*
            Eg. 1234
            1. take 1 -> take 12 -> take 123 (now its greater so return)
            2. take 
        */
        return ways(s, 0);
    }
};
