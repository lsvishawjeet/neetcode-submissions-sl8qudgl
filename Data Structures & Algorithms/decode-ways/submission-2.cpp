class Solution {
public:
    int ways(string s, int index, vector<int>& dp){
        if(index == s.length()) return 1;
        if(index >= s.length()) return 0;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];

        int res = ways(s, index+1, dp);
        if(s[index]=='1' || s[index]=='2' && s[index+1]<='6'){
            res += ways(s, index+2, dp);
        }
        return dp[index] = res;
    }
    int numDecodings(string s) {
        // algorithm
        // take one and take two
        /*
            Eg. 1234
            1. take 1 -> take 12 -> take 123 (now its greater so return)
            2. take 
        */
        vector<int> dp(s.length(), -1);
        return ways(s, 0, dp);
    }
};
